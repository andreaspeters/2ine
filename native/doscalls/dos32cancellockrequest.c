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

APIRET APIENTRY Dos32CancelLockRequest(HFILE hFile, PFILELOCK pflLock) {
  TRACE_NATIVE("%s(%s, %lx)", __FUNCTION__, hFile, pflLock);

  FILELOCKL flLockL;

  if (pflLock==NULL) {
    return ERROR_INVALID_PARAMETER;
  }

  flLockL.lOffset=pflLock->lOffset;
  flLockL.lRange=pflLock->lRange;

  return Dos32CancelLockRequestL(hFile, &flLockL);
};
