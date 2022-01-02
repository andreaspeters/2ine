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


HAB WinInitialize(ULONG flOptions) {
  TRACE_NATIVE("WinInitialize(%u)", (uint) flOptions);

  dw_app_id_set("org.dbsoft.dwindows.dwtest", "Dynamic Windows Test");

  /* Enable full dark mode on platforms that support it */
  if(getenv("DW_DARK_MODE"))
    dw_feature_set(DW_FEATURE_DARK_MODE, DW_DARK_MODE_FULL);
  /* Initialize the Dynamic Windows engine */
  dw_init(TRUE, 0, NULL);
} // WinInitialize



