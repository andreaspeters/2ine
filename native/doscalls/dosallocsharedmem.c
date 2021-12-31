
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
#include <string.h>

APIRET DosAllocSharedMem(PPVOID pBaseAddress, PSZ pszName, ULONG ulObjectSize, ULONG ulFlags ) {
  TRACE_NATIVE("%s(%s, %s, %s)", __FUNCTION__, pBaseAddress, pszName, ulObjectSize, ulFlags);
  
  int shmFd;

  if (! pBaseAddress || ! pszName)
    return ERROR_INVALID_PARAMETER;

  while(*pszName) {
    *pszName=toupper(*pszName);
    pszName++;
  }

  if (strstr(pszName, "\\SHAREMEM\\") != pszName) {
    return ERROR_INVALID_NAME;
  }

  shmFd = shm_open(pszName, ulFlags, 0666);
  ftruncate(shmFd, ulObjectSize);
  pBaseAddress = mmap(0, 8193, PROT_WRITE, MAP_SHARED, shmFd, 0);


  return 0;
}
