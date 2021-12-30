#include "../os2native.h"
#include "viocalls.h"

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


APIRET16 VioSetAnsi(USHORT Indicator, HVIO VioHandle) {
    TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return 0;
}

APIRET16 VioSetState(PVOID RequestBlock, HVIO VioHandle) {
    TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return 0;
}
