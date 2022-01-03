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


BOOL WinTerminate(HAB hab)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return TRUE;
} // WinTerminate

ERRORID WinGetLastError(HAB hab)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
} // WinGetLastError

HMQ WinCreateMsgQueue(HAB hab, LONG cmsg)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return NULL;
} // WinCreateMsgQueue

BOOL WinDestroyMsgQueue(HMQ hmq)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return NULL;
} // WinDestroyMsgQueue

MRESULT WinSendMsg(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return (MRESULT) 0;
} // WinSendMsg

BOOL WinPostMsg(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return TRUE;
} // WinPostMsg

BOOL WinPostQueueMsg(HMQ hmq, ULONG msg, MPARAM mp1, MPARAM mp2)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return FALSE;
} // WinPostQueueMsg

HWND WinCreateStdWindow(HWND hwndParent, ULONG flStyle, PULONG pflCreateFlags, PSZ pszClientClass, PSZ pszTitle, ULONG styleClient, HMODULE hmod, ULONG idResources, PHWND phwndClient)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return 0;
} // WinCreateStdWindow

BOOL WinDestroyWindow(HWND hwnd)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return TRUE;
} // WinDestroyWindow


BOOL WinFillRect(HPS hps, PRECTL prcl, LONG lColor)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return NULL;
} // WinBeginPaint

HPS WinBeginPaint(HWND hwnd, HPS hps, PRECTL prclPaint)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return NULL;
} // WinBeginPaint

BOOL WinEndPaint(HPS hps)
{
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
    return TRUE;
} // WinEndPaint

// end of pmwin.c ...


