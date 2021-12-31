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


APIRET APIENTRY  DosSetFilePtrL(HFILE hFile, LONGLONG ib, ULONG method, PLONGLONG pibActual) {
  TRACE_NATIVE("%s(...)", __FUNCTION__);

  return DosSetFilePtrL(hFile, ib, method, (ULONGLONG *)pibActual);
}
