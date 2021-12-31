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

APIRET DosSetPriority(ULONG ulScope, ULONG ulClass, LONG lDelta, ULONG ulID) {
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return 0;
}

APIRET Dos32CancelLockRequestL(HFILE hFile, PFILELOCKL pflLock) {
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return 0;
}

APIRET DosQueryMem(PPVOID pBaseAddress, PULONG pulRegionSize, PULONG pulAllocationFlags ) {
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return ERROR_ACCESS_DENIED;
}

APIRET DosEnterCritSec() {
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return 0;
}

APIRET DosExitCritSec() {
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return 0;
}


