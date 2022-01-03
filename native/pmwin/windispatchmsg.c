/**
 * 2ine; an OS/2 emulator for Linux.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Ryan C. Gordon.
 */

#include "../os2native.h"
#include "pmwin.h"
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

extern SWindows** windows;

MRESULT WinDispatchMsg(HAB hab, PQMSG pqmsg) {
  TRACE_NATIVE("%s(%u, %p, %d)", __FUNCTION__, (uint) hab, pqmsg, pqmsg->msg);  

  windows[0]->WindowClass(0, pqmsg->msg,  pqmsg->mp1, pqmsg->mp2);

  return 0;
} // WinDispatchMsg



