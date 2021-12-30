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

#define DATASPACE_READ    0x00000001
#define DATASPACE_WRITE   0x00000002

APIRET DosGetNamedSharedMem(PPVOID ppb, PSZ pszName, ULONG flag) {
  TRACE_NATIVE("%s(%s, %s, %s)", __FUNCTION__, ppb, pszName, flag);

  ULONG rights = 0;

  if (! ppb || ! pszName)
    return ERROR_INVALID_PARAMETER;

  while(*pszName) {
    *pszName=toupper(*pszName);
    pszName++;
  }

  if (strstr(pszName, "\\SHAREMEM\\") != pszName) {
    return ERROR_INVALID_NAME;
  }

  if (flag & PAG_READ) {
    rights |= DATASPACE_READ;
  }

  if (flag & PAG_WRITE) {
    rights |= DATASPACE_WRITE;
  }

  if (flag & PAG_EXECUTE) {
    rights |= DATASPACE_READ;
  }

  ppb = shm_open(pszName, flag, 0666);

  return 0;
}
