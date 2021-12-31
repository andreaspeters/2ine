/**
 * 2ine; an OS/2 emulator for Linux.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Ryan C. Gordon.
 */

#ifndef _INCL_MSG_H_
#define _INCL_MSG_H_

#include "os2types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CCHMAXPATH 260

/* MSG file header */
typedef struct {
  char magic[8];                  /* file header magic                       */
  char id[3];                     /* message file ID (SYS, NET, REX or etc.) */
  unsigned short msgs_no;         /* total number of messages in file        */
  unsigned short firstmsgno;      /* first message number                    */
  char is_offs_16bits;            /* are offsets 32/16 bits?                 */
  unsigned short version;         /* file format version                     */
  unsigned short idx_ofs;         /* file index offset                       */
  unsigned short ctry_info_ofs;   /* country info offset                     */
  unsigned short next_ctry_info;  /* next country info (if the file is a multi-language) */
  char pad[7];                    /* padding/reserved                        */
} msghdr_t;

OS2EXPORT APIRET16 OS2API16 Dos16PutMessage(USHORT hfile, USHORT cbMsg, PCHAR pBuf) OS2APIINFO(ord=1,name=DOSPUTMESSAGE);
OS2EXPORT APIRET16 OS2API16 Dos16TrueGetMessage(PVOID pTable, USHORT cTable, PCHAR pData, USHORT cbBuf, USHORT msgnum, PCHAR pFilename, PUSHORT pcbMsg, PVOID msgseg) OS2APIINFO(ord=2,name=DOSTRUEGETMESSAGE);
OS2EXPORT APIRET OS2API DosTrueGetMessage(PVOID pTable, USHORT cTable, PCHAR pData, USHORT cbBuf, USHORT msgnum, PCHAR pFilename, PUSHORT pcbMsg, PVOID msgseg) OS2APIINFO(6);
OS2EXPORT APIRET OS2API DosPutMessage(HFILE hfile, ULONG cbMsg, PCHAR pBuf) OS2APIINFO(5);
OS2EXPORT APIRET OS2API DosInsertMessage(PCHAR *pTable, ULONG cTable, PSZ pszMsg, ULONG cbMsg, PCHAR pBuf, ULONG cbBuf, PULONG pcbMsg) OS2APIINFO(4);

#ifdef __cplusplus
}
#endif

#endif

// end of msg.h ...

