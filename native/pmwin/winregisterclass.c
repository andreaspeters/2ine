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

BOOL WinRegisterClass(HAB hab, PSZ pszClassName, PFNWP pfnWndProc, ULONG flStyle, ULONG cbWindowData) {
  TRACE_NATIVE("%s(%u, '%s', %p, %u, %u)", __FUNCTION__, (uint) hab, pszClassName, pfnWndProc, (uint) flStyle, (uint) cbWindowData);

  // TODO: Search hab in array to see if it's exists, if not, add it, of yes, do nothing
  windows[0]->WindowClass = pfnWndProc;
  windows[0]->Hab = hab;

  return TRUE;
} // WinRegisterClass

// end of pmwin.c ...


