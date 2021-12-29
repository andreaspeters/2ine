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

APIRET APIENTRY Dos32CancelLockRequest(HFILE hFile, PFILELOCK pflLock)
{
  FILELOCKL flLockL;
  APIRET rc;

  TRACE_NATIVE("%s enter\n", __FUNCTION__);
  TRACE_NATIVE("hFile=%lx\n", hFile);

  if (pflLock==NULL)
  {
    return ERROR_INVALID_PARAMETER;
  }

  flLockL.lOffset=pflLock->lOffset;
  flLockL.lRange=pflLock->lRange;

  rc = Dos32CancelLockRequestL(hFile, &flLockL);
  TRACE_NATIVE("flLock=%lx\n", *pflLock);
  TRACE_NATIVE("%s exit => %lx\n", __FUNCTION__, rc);
  return rc;
};
