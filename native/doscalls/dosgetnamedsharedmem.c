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
#include <sys/shm.h>
#include <string.h>

APIRET DosGetNamedSharedMem(PPVOID pBaseAddress, PSZ pszName, ULONG ulFlags) {
  TRACE_NATIVE("%s(%s)", __FUNCTION__, pszName);

  return DosAllocCreateSharedMem(pBaseAddress, pszName, 0, ulFlags, FALSE);
}
