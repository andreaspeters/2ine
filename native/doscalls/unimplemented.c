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

#include "doscalls-lx.h"


APIRET DosSetPriority(ULONG ulScope, ULONG ulClass, LONG lDelta, ULONG ulID)
{
    TRACE_NATIVE("Unimplemented DosSetPriority(%d, %d, %d, %d)", ulScope, ulClass, lDelta, ulID);
    return 0;
} // DosSetPriority


