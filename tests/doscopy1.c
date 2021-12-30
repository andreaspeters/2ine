 #define INCL_DOSFILEMGR   /* File Manager values */
 #define INCL_DOSERRORS    /* DOS error values    */
 #include <os2.h>
 #include <stdio.h>
 #include <string.h>

int main(VOID) {
   UCHAR   achSourceString[80]  = "test"; /* String to transform */
   UCHAR   achTargetString[200] = "test2";           /* Destination string buffer */
   APIRET  rc                   = NO_ERROR;     /* Return code */


   rc = DosCopy(achSourceString,             /* Name of file to be copied    */
                achTargetString,             /* Name of the target file      */
                DCPY_EXISTING);   /* Copy even if target file already exists */

   if (rc != NO_ERROR) {
      printf("DosCopy error: return code = %u\n", rc);
      return 1;
   } else  printf ("Backup file %s created.\n", achTargetString);
   return NO_ERROR;
}
