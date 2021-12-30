#define INCL_DOSMEMMGR
#include <bsememf.h>
#include <os2.h>

PVOID BaseAddress;
      /* Pointer to the base address of the allocated memory. */

UCHAR Name[40];
      /* Pointer to the requested name of the memory block */
      /* which we are about to allocate.                   */

ULONG AttributeFlags;
      /* Flags describing the memory block's characteristics. */

APIRET rc;
      /* Receiving the return code */

strcpy(Name,"\\SHAREMEM\\BLOCK.DAT");   
      /* Name of the shared memory block. */
      /* Note the \\SHAREMEM\\ prefix.    */   

AttributeFlags = PAG_WRITE | PAG_READ | PAG_COMMIT;
      /* We request read and write access to the shared memory */
      /* block, and also have the pages of the memory block    */
      /* committed at once within the virtual memory.          */

rc = DosGetNamedSharedMem( &BaseAddress, Name, AttributeFlags);

if (rc != 0)
{
   /* We have an error we must take care of. */
}
