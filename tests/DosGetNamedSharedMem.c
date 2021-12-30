#define INCL_DOSMEMMGR
#define INCL_DOSFILEMGR   /* File Manager values */
#define INCL_DOSERRORS    /* DOS error values    */
#include <os2.h>
#include <stdio.h>
#include <string.h>


int main(VOID) {
  PVOID BaseAddress;
  UCHAR Name[40];
  ULONG AttributeFlags;
  APIRET rc;
   
  strcpy(Name,"\\SHAREMEM\\BLOCK.DAT");   
  AttributeFlags = 0x00000001;

  rc = DosAllocSharedMem(&BaseAddress, Name, 8192, AttributeFlags);
  if (rc != 0)
  {
    printf("DosAllocShrSeq error: return code = %u\n", rc);
    /* We have an error we must take care of. */
  }

  rc = DosGetNamedSharedMem( &BaseAddress, Name, AttributeFlags);
  
  if (rc != 0)
  {
    printf("DosGetNameSharedMem error: return code = %u\n", rc);
    /* We have an error we must take care of. */
  }
  printf("OK rc = %u\n", rc);
  return rc;
}
