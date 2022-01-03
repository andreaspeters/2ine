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


MRESULT WinDefWindowProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    TRACE_NATIVE("WinDefWindowProc(%u, %u, %p, %p)", (uint) hwnd, (uint) msg, mp1, mp2);

    switch (msg) {
        // this whole block just returns zero without further processing.
        case WM_ACTIVATE:
        case WM_APPTERMINATENOTIFY:
        case WM_ADJUSTWINDOWPOS:
        case WM_CALCFRAMERECT:
        case WM_COMMAND:
        case WM_CONTROL:
        case WM_CREATE:
        case WM_CTLCOLORCHANGE:
        case WM_DESTROY:
        case WM_DRAWITEM:
        case WM_ENABLE:
        case WM_ERASEBACKGROUND:
        case WM_ERROR:
        case WM_FORMATFRAME:
        case WM_HSCROLL:
        case WM_INITDLG:
        case WM_INITMENU:
        case WM_JOURNALNOTIFY:
        case WM_MATCHMNEMONIC:
        case WM_MEASUREITEM:
        case WM_MENUEND:
        case WM_MINMAXFRAME:
        case WM_MOUSEMAP:
        case WM_MOVE:
        case WM_NEXTMENU:
        case WM_NULL:
        case WM_PCONTROL:
        case WM_PRESPARAMCHANGED:
        case WM_PSETFOCUS:
        case WM_PSIZE:
        case WM_PSYSCOLORCHANGE:
        case WM_QUERYACCELTABLE:
        case WM_QUIT:
        case WM_SAVEAPPLICATION:
        case WM_SEM1:
        case WM_SEM2:
        case WM_SEM3:
        case WM_SEM4:
        case WM_SETACCELTABLE:
        case WM_SETFOCUS:
        case WM_SETHELPINFO:
        case WM_SETSELECTION:
        case WM_SETWINDOWPARAMS:
        case WM_SHOW:
        case WM_SIZE:
        case WM_SUBSTITUTESTRING:
        case WM_SYSCOLORCHANGE:
        case WM_SYSCOMMAND:
        case WM_SYSVALUECHANGED:
        case WM_TIMER:
        case WM_TRACKFRAME:
        case WM_TRANSLATEACCEL:
        //case WM_TRANSLATEMNEMONIC:  // !!! FIXME: this is in the SDK reference but not the SDK headers.
        case WM_UPDATEFRAME:
        case WM_VRNDISABLED:
        case WM_VRNENABLED:
        case WM_VSCROLL:

        // the SDK reference manual doesn't list default actions for these messages, but it's probably just "return zero".
        case WM_MSGBOXINIT:
        case WM_MSGBOXDISMISS:
            TRACE_NATIVE("WinDefWindowProc(WM_MSGBOXDISMISS)");
            return (MRESULT) 0;

        // this whole block just returns one without further processing.
        case WM_MENUSELECT:
            TRACE_NATIVE("WinDefWindowProc(WM_MENUSELECT)");
            return (MRESULT) 1;

        // this block sends the message to the window owner (if one exists), or otherwise returns 0.
        case WM_BEGINDRAG:
        case WM_BEGINSELECT:
        case WM_BUTTON1CLICK:
        case WM_BUTTON1DBLCLK:
        case WM_BUTTON1MOTIONSTART:
        case WM_BUTTON1MOTIONEND:
        case WM_BUTTON1UP:
        case WM_BUTTON2CLICK:
        case WM_BUTTON2DBLCLK:
        case WM_BUTTON2MOTIONSTART:
        case WM_BUTTON2MOTIONEND:
        case WM_BUTTON2UP:
        case WM_BUTTON3CLICK:
        case WM_BUTTON3DBLCLK:
        case WM_BUTTON3MOTIONSTART:
        case WM_BUTTON3MOTIONEND:
        case WM_BUTTON3UP:
        case WM_CHAR:
        case WM_CHORD:
        case WM_CONTEXTMENU:
        case WM_ENDDRAG:
        case WM_ENDSELECT:
        case WM_OPEN:
        case WM_PACTIVATE:
        case WM_QUERYCTLTYPE:
        case WM_QUERYHELPINFO:
        case WM_QUERYTRACKINFO:
        case WM_SINGLESELECT:
        case WM_TEXTEDIT:
            TRACE_NATIVE("WinDefWindowProc(WM_TEXTEDIT)");
        // These messages actually do something specific in default processing...
        case WM_HITTEST:

        case WM_BUTTON1DOWN:
        case WM_BUTTON2DOWN:
        case WM_BUTTON3DOWN:
        case WM_CALCVALIDRECTS:
        case WM_CLOSE:
        case WM_CONTROLPOINTER:
        case WM_FOCUSCHANGE:
        case WM_HELP:
        case WM_MOUSEMOVE:
        case WM_PAINT:
        case WM_PPAINT:
        case WM_QUERYCONVERTPOS:
        case WM_QUERYWINDOWPARAMS:
        case WM_REALIZEPALETTE:
        case WM_WINDOWPOSCHANGED:
            TRACE_NATIVE("WinDefWindowProc(WM_WINDOWPOSCHANGED)");
            break;

        default:
            TRACE_NATIVE("WinDefWindowProc(DEFAULT)");
            break;
    }

    return (MRESULT) 0;
} // WinDefWindowProc
