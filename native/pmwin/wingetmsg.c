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

BOOL WinGetMsg(HAB hab, PQMSG pqmsg, HWND hwndFilter, ULONG msgFilterFirst, ULONG msgFilterLast) {
  TRACE_NATIVE("%s(%d, %s, %u, %u)", __FUNCTION__, hab, pqmsg->msg, msgFilterFirst, msgFilterLast);

//  dw_window_show(GLoaderState.mainwindow);
  dw_main_sleep(1000);  
//  dw_main();
  return (pqmsg->msg != WM_QUIT) ? TRUE : FALSE;
  return TRUE;
} // WinGetMsg



