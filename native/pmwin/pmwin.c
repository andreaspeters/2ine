#include "../os2native.h"
#include "pmwin.h"

#include "pmwin-lx.h"

// NOTE: PM reference manual says OS/2 generally ignores the HAB you pass
//  to functions, instead getting that info from the current thread, but
//  other IBM platforms might not do that, so programs should always pass
//  a valid HAB to everything. Things like WinCreateWindow() probably rely
//  on the current thread's HAB without requiring the API call to specify
//  it in any case.
// So current approach: keep a pointer to the anchor block in the TIB, and
//  the anchor block keeps a copy of it's HAB. When the anchor block is
//  needed, we pull it from the TIB directly, and if it's in a function
//  where a HAB is specified, we fail if the handles don't match.
// If I later find out that OS/2 doesn't even care even if you give it a
//  bogus HAB, we can relax this check.


#define FIRST_HWND_VALUE 10
#define FIRST_HPS_VALUE 10

// end of pmwin.c ...
