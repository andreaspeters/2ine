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

APIRET DosQuerySysInfo(ULONG first, ULONG last, PVOID _buf, ULONG buflen) {
    TRACE_NATIVE("%s(%u, %u, %p, %u)", __FUNCTION__, (uint) first, (uint) last, _buf, (uint) buflen);

    uint32 *buf = (uint32 *) _buf;
    if (last < first) return ERROR_INVALID_PARAMETER;
    if ( (buflen / sizeof (uint32)) < ((last - first) + 1) ) return ERROR_BUFFER_OVERFLOW;
    for (uint32 varid = first; varid <= last; varid++) {
        switch (varid) {
            case QSV_MAX_PATH_LENGTH: *(buf++) = PATH_MAX; break;
            case QSV_MAX_TEXT_SESSIONS: *(buf++) = 999999; break;
            case QSV_MAX_PM_SESSIONS: *(buf++) = 999999; break;
            case QSV_MAX_VDM_SESSIONS: *(buf++) = 0; break;
            case QSV_BOOT_DRIVE: *(buf++) = 3; break;  // "C:"
            case QSV_DYN_PRI_VARIATION: *(buf++) = 1; break;
            case QSV_MAX_WAIT: *(buf++) = 1; break;
            case QSV_MIN_SLICE: *(buf++) = 1; break;
            case QSV_MAX_SLICE: *(buf++) = 10; break;
            case QSV_PAGE_SIZE: *(buf++) = 4096; break;
            // !!! FIXME: change the version number in some way so apps can know this isn't actually OS/2.
            case QSV_VERSION_MAJOR: *(buf++) = 20; break;   // OS/2 Warp 4.5
            case QSV_VERSION_MINOR: *(buf++) = 45; break;   // OS/2 Warp 4.5
            case QSV_VERSION_REVISION: *(buf++) = 0; break; // OS/2 Warp 4.5

            case QSV_MS_COUNT: {
                static long startoffset = 0;
                if (startoffset == 0) {
                    struct timespec ts;
                    struct sysinfo info;
                    sysinfo(&info);
                    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
                    startoffset = info.uptime - ((long) ts.tv_sec);
                } // if

                struct timespec ts;
                clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
                *(buf++) = (uint32) (((long) ts.tv_sec) - startoffset);
                break;
            } // case

            case QSV_TIME_LOW: *(buf++) = (uint32) time(NULL); break;
            case QSV_TIME_HIGH: *(buf++) = 0; break;  // !!! FIXME: 32-bit Linux time_t is 32-bits!

            case QSV_TOTPHYSMEM: {
                struct sysinfo info;
                sysinfo(&info);
                *(buf++) = (uint32) info.totalram;
                break;
            } // case

            case QSV_TOTRESMEM: {
                struct sysinfo info;
                sysinfo(&info);
                *(buf++) = (uint32) info.totalram - info.freeram;  // !!! FIXME: probably not right?
                break;
            } // case

            case QSV_TOTAVAILMEM: {
                struct sysinfo info;
                sysinfo(&info);
                *(buf++) = (uint32) info.freeram;
                break;
            } // case

            case QSV_MAXPRMEM: *(buf++) = 0x7FFFFFFF; break;  // !!! FIXME: should I list all 4 gigs? Also: what about machines with < 2 gigs?
            case QSV_MAXSHMEM: *(buf++) = 0x7FFFFFFF; break;  // !!! FIXME: should I list all 4 gigs? Also: what about machines with < 2 gigs?

            case QSV_TIMER_INTERVAL: *(buf++) = 10; break;
            case QSV_MAX_COMP_LENGTH: *(buf++) = NAME_MAX; break;
            case QSV_FOREGROUND_FS_SESSION: *(buf++) = 1; break;  // !!! FIXME
            case QSV_FOREGROUND_PROCESS: *(buf++) = 1; break;  // !!! FIXME

            default: return ERROR_INVALID_PARAMETER;
        } // switch
    } // for

    return NO_ERROR;
} // DosQuerySysInfo


