/**
 * 2ine; an OS/2 emulator for Linux.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Ryan C. Gordon.
 */

#include "os2native16.h"
#include "doscalls/doscalls.h"
#include "msg.h"

#include <unistd.h>

#include "msg-lx.h"

APIRET DosPutMessage(HFILE handle, ULONG msglen, PCHAR msg)
{
    TRACE_NATIVE("DosPutMessage(%u, %u, %p)", (uint) handle, (uint) msglen, msg);
    FIXME("really implement this");
    write(handle, msg, msglen);
    return NO_ERROR;
} // DosPutMessage

APIRET16 Dos16PutMessage(USHORT handle, USHORT msglen, PCHAR msg)
{
    TRACE_NATIVE("Dos16PutMessage(%u, %u, %p)", (uint) handle, (uint) msglen, msg);
    FIXME("really implement this");
    write(handle, msg, msglen);
    return NO_ERROR;
} // Dos16PutMessage

APIRET16 Dos16TrueGetMessage(PVOID pTable, USHORT cTable, PCHAR pData, USHORT cbBuf, USHORT msgnum, PCHAR pFilename, PUSHORT pcbMsg, PVOID msgseg)
{
    TRACE_NATIVE("Dos16TrueGetMessage(%p, %u, %p, %u, %u, %p, %p, %p)", pTable, cTable, pData, cbBuf, msgnum, pFilename, pcbMsg, msgseg);
    void *msgdat = msgseg;
    int offset = *(uint16_t *)(msgdat + 14);
    offset = *(uint16_t *)(msgdat + offset + 4);
    int count = *(uint16_t *)(msgdat + offset + 3);
    uint16_t *msgarr = (uint16_t *)(msgdat + offset + 5);
    int i, j = 0;
    for (i = 0; i < count; i++)
    {
        if(*(uint16_t *)(msgdat + msgarr[i]) == msgnum)
            break;
    }
    if (i == count) return ERROR_MR_MID_NOT_FOUND;
    int msglen = *(PUSHORT)(msgdat + msgarr[i] + 2);
    char *substr, *msg = (char *)(msgdat + msgarr[i] + 4);
    int sub;
    if (msg[0] == 'E')
    {
        j = 8;
        if (cbBuf > 8)
            sprintf(pData, "SYS%04d:", msgnum);
    }
    for (i = 1; (i < msglen) && (j < cbBuf); i++, j++)
    {
        if (msg[i] == '%')
        {
            sub = msg[++i] - '1';
            if ((sub < 0) || (sub >= cTable)) return ERROR_MR_INV_MSGF_FORMAT;
            substr = GLoaderState.convert1616to32(((uint32_t *)pTable)[sub]);
            strcpy(&pData[j], substr);
            j += strlen(substr) - 1;
        }
        else
            pData[j] = msg[i];
    }
    *pcbMsg = j;
    return NO_ERROR;
}

APIRET DosInsertMessage(PCHAR *pTable, ULONG cTable, PSZ pszMsg, ULONG cbMsg, PCHAR pBuf, ULONG cbBuf, PULONG pcbMsg) {
  TRACE_NATIVE("Unimplemented %s(...)", __FUNCTION__);
  return -1;
}

APIRET16 DosTrueGetMessage(void *MsgSeg, PCHAR *Table, ULONG TableSize, PCHAR Buf, ULONG BufSize, ULONG MsgNumber, PSZ FileName, PULONG MsgSize) {
  TRACE_NATIVE("%s(%s, %s, %s, %s, %s, %s, %s, %s)", __FUNCTION__, MsgSeg, Table, TableSize, Buf, BufSize, MsgNumber, FileName, MsgSize);

  APIRET rc = NO_ERROR;
  ULONG  cbFile;
  void   *buf;
  char   *msg;
  char   id[4];
  char   str[CCHMAXPATH];
  msghdr_t *hdr = (msghdr_t *)MsgSeg;
  int    msgoff, msgend, msglen, i;

  ULONG  len;

  /* Check arguments */
  if (TableSize > 9) {
    return ERROR_MR_INV_IVCOUNT;
  }

  if (!Buf || !BufSize) {
    return ERROR_INVALID_PARAMETER;
  }

  if (!MsgSeg) {
    return ERROR_MR_UN_ACC_MSGF; // Unable to access message file
  }

  // from this point, the file/msg seg is loaded at msgSeg address
  msg = (char *)MsgSeg;  // message pointer
  hdr = (msghdr_t *)msg; // message header
  MsgNumber -= hdr->firstmsgno;

  if (MsgNumber > hdr->msgs_no) {
    return ERROR_MR_MID_NOT_FOUND; // ???
  }

  // get message offset
  if (hdr->is_offs_16bits) // if offset is 16 bits
    msgoff = (int)(*(unsigned short *)(msg + hdr->idx_ofs + 2 * MsgNumber));
  else // it is 32 bits
    msgoff = (int)(*(unsigned long *)(msg + hdr->idx_ofs + 4 * MsgNumber));

  if (MsgNumber + 1 == hdr->msgs_no) {
    if (hdr->next_ctry_info)
      msgend = hdr->next_ctry_info;
    else
      msgend = cbFile; // EOF
  }
  else
  {
    // get next message offset
    if (hdr->is_offs_16bits) // if offset is 16 bits
      msgend = (int)(*(unsigned short *)(msg + hdr->idx_ofs + 2 * (MsgNumber + 1)));
    else // it is 32 bits
      msgend = (int)(*(unsigned long *)(msg + hdr->idx_ofs + 4 * (MsgNumber + 1)));
  }

  if (msgoff > cbFile || msgend > cbFile) {
    return ERROR_MR_MSG_TOO_LONG;
  }

  // message length
  msglen = msgend - msgoff - 1;

  // msg now points to the desired message
  msg += msgoff;

  // OS/2 actually does not check for prefixes
  //if (*msg != 'E' && *msg != 'W' &&
  //    *msg != 'P' && *msg != 'I' &&
  //    *msg != 'H' && *msg != '?')
  //  {
  //    rc = ERROR_MR_INV_MSGF_FORMAT;
  //    goto DOSTRUEGETMESSAGE_EXIT;
  //  }

  // message file ID
  strncpy(id, hdr->id, 3);
  id[3] = '\0';

  /* switch (*msg)
  {
    case 'E': // Error
    case 'W': // Warning
    case 'I': // Info
      // prepend the Warning/Error ID (like SYS3175: )
      sprintf(str, "%s%04u: ", id, msgnumber);
      DosPutMessage(1, strlen(str), str);
      break;
    default:
      break;
  } */

  // skip message type letter
  msg++;

  // substitute %? to the actual parameters
  rc = DosInsertMessage(Table, TableSize, msg, msglen, Buf, BufSize, MsgSize);

  // finally, free file buffer
  DosFreeMem(buf);

  return rc;
}

// end of msg.c ...

