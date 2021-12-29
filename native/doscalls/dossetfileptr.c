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


APIRET APIENTRY  DosSetFilePtrL(HFILE hFile, LONGLONG ib, ULONG method, PLONGLONG pibActual)
{
  APIRET rc;
  TRACE_NATIVE("%s enter\n", __FUNCTION__);
  TRACE_NATIVE("hFile=%lx\n", hFile);
  TRACE_NATIVE("ib=%lld\n", ib);
  TRACE_NATIVE("method=%lx\n", method);
  rc = DosSetFilePtrL(hFile, ib, method, (ULONGLONG *)pibActual);
  TRACE_NATIVE("ibActual=%lld\n", *pibActual);
  TRACE_NATIVE("%s exit => %lx\n", __FUNCTION__, rc);
  return rc;
}
