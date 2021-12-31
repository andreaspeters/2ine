#include "../os2native.h"
#include "doscalls.h"

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


APIRET DosEditName(ULONG metalevel, PSZ pszSource, PSZ pszEdit, PSZ pszTarget, ULONG cbTarget) {
  TRACE_NATIVE("%s(...)", __FUNCTION__);

  if (metalevel != 1) {
    return ERROR_INVALID_PARAMETER;
  }

  if (!cbTarget) {
    return ERROR_INVALID_PARAMETER;
  }

  if (!pszTarget) {
    return ERROR_INVALID_PARAMETER;
  }

  char *s;
  s = pszTarget;
  while (--cbTarget) {
     switch (*s = *pszEdit++) {
       case '?':
         // '.' does not copy a character when the end of
         // filename or extension is reached
         if (*pszSource == '.' || !*pszSource)
           continue;
 
         *s++ = *pszSource;
         if (*pszSource)
           ++pszSource;
         break;
       case '*':
         for (;;)
         {
           *s = *pszSource;
           cbTarget--;
           if (*pszSource)
             pszSource++;
           else
             break;
           if (*s == *pszEdit)
             break;
           if (*s == '\0')
             break;
           s++;
         }
         *s = *pszEdit;
         cbTarget++;
         break;
       case '\0':
         *s = '\0';
         return 0;
       case '.':
         s++;
         break;
       default:
         if (*pszSource)
           ++pszSource;
         s++;
         break;
     }
   }  

  return 0;
} 


