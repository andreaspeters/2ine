#define INCL_DOSMEMMGR
#include <bsememf.h>
#include <os2.h>

int main(VOID) {
  PVOID BaseAddress;
  UCHAR Name[40];
  ULONG AttributeFlags;
  APIRET rc;
  
  strcpy(Name,"\\SHAREMEM\\BLOCK.DAT");   
  
  AttributeFlags = PAG_WRITE | PAG_READ | PAG_COMMIT;
  
  rc = DosGetNamedSharedMem( &BaseAddress, Name, AttributeFlags);
  
  if (rc != 0)
  {
     /* We have an error we must take care of. */
  }
}
