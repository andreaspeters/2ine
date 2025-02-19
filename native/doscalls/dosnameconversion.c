/*----------------------------------------------------------------------------*/
/*                                                                            */
/* Description: This file includes the code to the OS/2 memory manager.       */
/*                                                                            */
/* Copyright (C) IBM Corporation 2003. All Rights Reserved.                   */
/* Copyright (C) W. David Ashley 2004-2010. All Rights Reserved.              */
/*                                                                            */
/* This program and the accompanying materials are made available under       */
/* the terms of the Common Public License v1.0 which accompanies this         */
/* distribution. A copy is also available at the following address:           */
/* http://www.ibm.com/developerworks/oss/CPLv1.0.htm                          */
/*                                                                            */
/* Redistribution and use in source and binary forms, with or                 */
/* without modification, are permitted provided that the following            */
/* conditions are met:                                                        */
/*                                                                            */
/* Redistributions of source code must retain the above copyright             */
/* notice, this list of conditions and the following disclaimer.              */
/* Redistributions in binary form must reproduce the above copyright          */
/* notice, this list of conditions and the following disclaimer in            */
/* the documentation and/or other materials provided with the distribution.   */
/*                                                                            */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS        */
/* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT          */
/* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS          */
/* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT   */
/* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,      */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,        */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY     */
/* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING    */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS         */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.               */
/*                                                                            */
/* https://sourceforge.net/p/os2linux/                                        */
/*----------------------------------------------------------------------------*/

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
#include <string.h>

VOID DosNameConversion(PSZ pszName, PUCHAR pSeparator, PUCHAR pRepl, BOOL uc) {
  TRACE_NATIVE("%s(%s)", __FUNCTION__, pszName);

  CHAR separator;
  CHAR replacement;
  PSZ tempName;

  if (pszName == NULL) {
      return;
  }

  /* set the delimiter to convert */
  if (pSeparator == NULL) {
      separator = '\\';
  }
  else {
      separator = *pSeparator;
  }

  /* set the replacement character */
  if (pRepl == NULL) {
      replacement = '/';
  }
  else {
      replacement = *pRepl;
  }

  /* now convert the characters */
  tempName = pszName;
  while (*tempName != '\0') {
      if (*tempName == separator) {
          *tempName = replacement;
      }
      tempName++;
  }

  /* covert the name to upper case if necessary */
  if (uc) {
      tempName = pszName;
      while (*tempName) {
          *tempName = (CHAR)toupper(*tempName);
          tempName++;
      }
  }
}
