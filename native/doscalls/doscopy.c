#include "../os2native.h"
#include "doscalls.h"

#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <bsd/string.h>

#define IOBUF_SIZ 8192
APIRET CopyDir(PSZ pszSrc, PSZ pszDst, ULONG ulOptions);
APIRET CopyFile(PSZ pszSrc, PSZ pszDst, ULONG ulOptions);

APIRET CopyDir(PSZ pszSrc, PSZ pszDst, ULONG ulOptions) {
  TRACE_NATIVE("%s(%s, %s, %d)", __FUNCTION__, pszSrc, pszDst, ulOptions);

  APIRET rc;
  DIR *dir;
  struct dirent *entry;
  char dstfilename[255];
  char srcfilename[255];

  if ((dir = opendir(pszSrc)) == NULL) {
      perror("opendir() error");
  } else {
    while ((entry = readdir(dir)) != NULL) {
      if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) {
        continue;
      }

      strcpy(dstfilename, pszDst);
      strcat(dstfilename, "/");
      strcat(dstfilename, entry->d_name);

      strcpy(srcfilename, pszSrc);
      strcat(srcfilename, "/");
      strcat(srcfilename, entry->d_name);
      TRACE_NATIVE("%s: %s, %s, %s", __FUNCTION__, entry->d_name, dstfilename, srcfilename);
      rc = CopyFile((PSZ)srcfilename, (PSZ)dstfilename, ulOptions); 
    }
    closedir(dir);
  }
}

APIRET CopyFile(PSZ pszSrc, PSZ pszDst, ULONG ulOptions) {
  TRACE_NATIVE("%s(%s, %s, %d)", __FUNCTION__, pszSrc, pszDst, ulOptions);

  int infd, outfd; 
  ssize_t ret, retout;  
  char buffer[IOBUF_SIZ];

  if ((strcmp(pszSrc, ".") == 0) || (strcmp(pszSrc, "..") == 0)) {
    return 0;
  }

  if ((strcmp(pszDst, ".") == 0) || (strcmp(pszDst, "..") == 0)) {
    return 0;
  }

  infd = open (pszSrc, O_RDONLY);
  if (infd == -1) {
     perror ("could not open input file");
     return 2;
  }

  outfd = open(pszDst, O_WRONLY | O_CREAT, 0644);
  if(outfd == -1){
     perror ("could not open output file");
     return 3;
  }

  while((ret = read (infd, &buffer, IOBUF_SIZ)) > 0){
    retout = write (outfd, &buffer, (ssize_t) ret);
    if(retout != ret){
      perror("could not write data into new file");
      return 4;
    }
  }
 
  /* Close file descriptors */
  close (infd);
  close (outfd);  
/*
  if (!(ulOptions&DCPY_EXISTING))
  {
    // if no file exists then we fail
    ulOpenType = OPEN_ACTION_FAIL_IF_EXISTS;
  } else {
    if (ulOptions&DCPY_APPEND)
    {
      // else or append
      ulOpenType = OPEN_ACTION_OPEN_IF_EXISTS;
    } else {
      // or replace
      ulOpenType = OPEN_ACTION_REPLACE_IF_EXISTS;
    }
  }
*/
  return NO_ERROR;
}

APIRET APIENTRY Dos32Copy(PSZ pszOld, PSZ pszNew, ULONG ulOptions) {
  FILESTATUS3 fileStatus;
  APIRET rc;

  #define DCPY_MASK ~(DCPY_EXISTING | DCPY_APPEND | DCPY_FAILEAS )

  TRACE_NATIVE("%s(%s, %s, %lx)", __FUNCTION__, pszOld, pszNew, ulOptions);

  //Check arguments
  if ((!pszOld) || (!pszNew)) return ERROR_INVALID_PARAMETER;
  // Also check for reserved options used
  if (ulOptions & DCPY_MASK) return ERROR_INVALID_PARAMETER;

  //Detect is source dir or file (also check is it exists)
  rc = DosQueryPathInfo(pszOld, FIL_STANDARD, &fileStatus, sizeof(FILESTATUS3));

  if (rc) {
    return rc;
  }

  // Perfom action based on source path type
  if (fileStatus.attrFile & FILE_DIRECTORY) {
    // DCPY_APPEND flag not valid in directory copy
    rc = CopyDir((PSZ)pszOld, (PSZ)pszNew, ulOptions & ~DCPY_APPEND);
  } else {
    rc = CopyFile((PSZ)pszOld, (PSZ)pszNew, ulOptions); 
  };

  return rc;
}


APIRET APIENTRY  Dos32Move(PSZ  pszOld, PSZ  pszNew) {
  FILESTATUS3 fileStatus;
  APIRET rc;

  TRACE_NATIVE("%s(%s, %s)", __FUNCTION__, pszOld, pszNew);

  //Check arguments
  if ((!pszOld) || (!pszNew)) return ERROR_INVALID_PARAMETER;

  //Detect is source dir or file (also check is it exists)
  rc = DosQueryPathInfo(pszOld, FIL_STANDARD,  &fileStatus, sizeof(FILESTATUS3)); 

  if (rc) {
    return rc;
  }

  // Perfom action based on source path type
  if (fileStatus.attrFile & FILE_DIRECTORY) {
    // DCPY_APPEND flag not valid in directory copy
    //rc = CopyTree((PSZ)pszOld, (PSZ)pszNew, 0, 1);
  } else {
    if (rc = CopyFile((PSZ)pszOld, (PSZ)pszNew, 0)) {
      return rc;
    }
    rc = DosDelete(pszOld);
  }

  return rc;
}
