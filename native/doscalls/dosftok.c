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
#include <sys/ipc.h>
#include <string.h>

key_t APIENTRY DosFtok(PSZ pszName) {
  TRACE_NATIVE("%s(%s)", __FUNCTION__, pszName);

  key_t mykey = -1; /* default is an error indicator */
  PSZ fsName;
  static char tempdir[] = "/tmp";
  struct stat statbuf;
  int rc;

  /* append Linux temporary directory to the front of the name */
  fsName = alloca(strlen(tempdir) + strlen(pszName) + 1);
  strcpy(fsName, tempdir);
  strcat(fsName, pszName);

  /* make sure the file exists */
  rc = stat(fsName, &statbuf);
  if (rc) {
      switch (errno) {
      case ENOENT:
      case ENOTDIR:
          TRACE_NATIVE(">>> %s: File not found, create one.", __FUNCTION__);
          /* file not found, so create it */
          rc = open(fsName, O_CREAT | O_EXCL, S_IRWXU | S_IRWXG);
          if (rc == -1) {
              return mykey;
          }
          close(rc);
          break;
      default:
          return mykey;
      }
  }

  /* now that we know the file exists we can ftok it */
  mykey = ftok(fsName, 'O');

  return mykey;
}

