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

unsigned long flStyle = DW_FCF_SYSMENU | DW_FCF_TITLEBAR | DW_FCF_TASKLIST | DW_FCF_DLGBORDER;

HWND WinCreateWindow(HWND hwndParent, PSZ pszClass, PSZ pszName, ULONG flStyle, LONG x, LONG y, LONG cx, LONG cy, HWND hwndOwner, HWND hwndInsertBehind, ULONG id, PVOID pCtlData, PVOID pPresParams) {
  TRACE_NATIVE("%s(%d, %s, %s, %d)", __FUNCTION__, hwndParent, pszClass, pszName, hwndOwner);
  HWND window = dw_window_new(hwndOwner, pszName, flStyle | DW_FCF_SIZEBORDER | DW_FCF_MINMAX);
  
  GLoaderState.mainwindow = window;
  return window;
} // WinCreateWindow



