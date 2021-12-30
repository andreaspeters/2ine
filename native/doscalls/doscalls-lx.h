/**
 * 2ine; an OS/2 emulator for Linux.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 */

/* THIS FILE IS AUTOGENERATED. DO NOT EDIT BY HAND. see lxapigen.pl */

/* This is glue code for OS/2 binaries. Native binaries don't need this. */
#if LX_LEGACY

static APIRET16 bridge16to32_Dos16CWait(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, pid);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, ppid);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PRESULTCODES16, pres);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, option);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, action);
    return Dos16CWait(action, option, pres, ppid, pid);
}

static VOID bridge16to32_Dos16Exit(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, result);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, action);
    Dos16Exit(action, result);
}

static APIRET16 bridge16to32_Dos16GetInfoSeg(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSEL, localseg);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSEL, globalseg);
    return Dos16GetInfoSeg(globalseg, localseg);
}

static APIRET16 bridge16to32_Dos16HoldSignal(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, action);
    return Dos16HoldSignal(action);
}

static APIRET16 bridge16to32_Dos16SetSigHandler(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, signumber);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, action);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, prevaction);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, prevaddress);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PFN, routine);
    return Dos16SetSigHandler(routine, prevaddress, prevaction, action, signumber);
}

static APIRET16 bridge16to32_Dos16AllocSeg(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, flags);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, psel);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, size);
    return Dos16AllocSeg(size, psel, flags);
}

static APIRET16 bridge16to32_Dos16ReallocSeg(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, sel);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, size);
    return Dos16ReallocSeg(size, sel);
}

static APIRET16 bridge16to32_Dos16FreeSeg(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, sel);
    return Dos16FreeSeg(sel);
}

static APIRET16 bridge16to32_Dos16GetHugeShift(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pcount);
    return Dos16GetHugeShift(pcount);
}

static APIRET16 bridge16to32_Dos16GetMachineMode(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PBYTE, pmode);
    return Dos16GetMachineMode(pmode);
}

static APIRET16 bridge16to32_Dos16Beep(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, dur);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, freq);
    return Dos16Beep(freq, dur);
}

static APIRET16 bridge16to32_Dos16ChDir(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(ULONG, res);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSZ, pszDir);
    return Dos16ChDir(pszDir, res);
}

static APIRET16 bridge16to32_Dos16ChgFilePtr(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PULONG, newoffset);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, whence);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(LONG, distance);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, handle);
    return Dos16ChgFilePtr(handle, distance, whence, newoffset);
}

static APIRET16 bridge16to32_Dos16Close(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, hFile);
    return Dos16Close(hFile);
}

static APIRET16 bridge16to32_Dos16Delete(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(ULONG, res);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSZ, pszFile);
    return Dos16Delete(pszFile, res);
}

static APIRET16 bridge16to32_Dos16DupHandle(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pHfile);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, hFile);
    return Dos16DupHandle(hFile, pHfile);
}

static APIRET16 bridge16to32_Dos16FindClose(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, hDir);
    return Dos16FindClose(hDir);
}

static APIRET16 bridge16to32_Dos16FindFirst(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(ULONG, res);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pcFileNames);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, cbBuf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, pfindbuf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, flAttribute);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSHORT, phdir);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSZ, pszFileSpec);
    return Dos16FindFirst(pszFileSpec, phdir, flAttribute, pfindbuf, cbBuf, pcFileNames, res);
}

static APIRET16 bridge16to32_Dos16FindNext(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pcFilenames);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, cbfindbuf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, pfindbuf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, hDir);
    return Dos16FindNext(hDir, pfindbuf, cbfindbuf, pcFilenames);
}

static APIRET16 bridge16to32_Dos16Open(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PEAOP2, peaop2);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, fsOpenMode);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, fsOpenFlags);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, ulAttribute);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(ULONG, cbFile);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PULONG, pulAction);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pHf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSZ, pszFileName);
    return Dos16Open(pszFileName, pHf, pulAction, cbFile, ulAttribute, fsOpenFlags, fsOpenMode, peaop2);
}

static APIRET16 bridge16to32_Dos16QCurDir(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, dirpathlen);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PBYTE, dirpath);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, drivenum);
    return Dos16QCurDir(drivenum, dirpath, dirpathlen);
}

static APIRET16 bridge16to32_Dos16QCurDisk(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PULONG, drivemap);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, drivenum);
    return Dos16QCurDisk(drivenum, drivemap);
}

static APIRET16 bridge16to32_Dos16QFileMode(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(ULONG, res);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, attr);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PCHAR, filepath);
    return Dos16QFileMode(filepath, attr, res);
}

static APIRET16 bridge16to32_Dos16QFsInfo(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, infobufsize);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PBYTE, infobuf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, fslevel);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, drivenum);
    return Dos16QFsInfo(drivenum, fslevel, infobuf, infobufsize);
}

static APIRET16 bridge16to32_Dos16QHandType(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pflags);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, ptype);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, handle);
    return Dos16QHandType(handle, ptype, pflags);
}

static APIRET16 bridge16to32_Dos16SetVec(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, prevaddress);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PFN, routine);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, vecnum);
    return Dos16SetVec(vecnum, routine, prevaddress);
}

static APIRET16 bridge16to32_Dos16GetEnv(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pcmdoffset);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, psel);
    return Dos16GetEnv(psel, pcmdoffset);
}

static APIRET16 bridge16to32_Dos16GetVersion(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pver);
    return Dos16GetVersion(pver);
}

static APIRET16 bridge16to32_Dos16GetPID(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PPIDINFO16, ppidinfo);
    return Dos16GetPID(ppidinfo);
}

static APIRET16 bridge16to32_Dos16GetCp(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pcCP);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, arCP);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, cb);
    return Dos16GetCp(cb, arCP, pcCP);
}

static APIRET16 bridge16to32_Dos16Read(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, pcbActual);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, cbRead);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, pBuffer);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, hFile);
    return Dos16Read(hFile, pBuffer, cbRead, pcbActual);
}

static APIRET16 bridge16to32_Dos16Write(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PUSHORT, actual);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, buflen);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PVOID, buf);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, h);
    return Dos16Write(h, buf, buflen, actual);
}

static APIRET16 bridge16to32_DosSemRequest(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(LONG, ms);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PHSEM16, sem);
    return DosSemRequest(sem, ms);
}

static APIRET16 bridge16to32_DosSemClear(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PHSEM16, sem);
    return DosSemClear(sem);
}

static APIRET16 bridge16to32_DosSemWait(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(LONG, ms);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PHSEM16, sem);
    return DosSemWait(sem, ms);
}

static APIRET16 bridge16to32_DosSemSet(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PHSEM16, sem);
    return DosSemSet(sem);
}

static APIRET16 bridge16to32_Dos16ExecPgm(uint8 *args) {
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSZ, pName);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PRESULTCODES16, pRes);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSZ, pEnv);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PSZ, pArg);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(USHORT, execFlag);
    LX_NATIVE_MODULE_16BIT_BRIDGE_ARG(SHORT, cbObjname);
    LX_NATIVE_MODULE_16BIT_BRIDGE_PTRARG(PCHAR, pObjname);
    return Dos16ExecPgm(pObjname, cbObjname, execFlag, pArg, pEnv, pRes, pName);
}

LX_NATIVE_MODULE_16BIT_SUPPORT()
    LX_NATIVE_MODULE_16BIT_API(Dos16CWait)
    LX_NATIVE_MODULE_16BIT_API(Dos16Exit)
    LX_NATIVE_MODULE_16BIT_API(Dos16GetInfoSeg)
    LX_NATIVE_MODULE_16BIT_API(Dos16HoldSignal)
    LX_NATIVE_MODULE_16BIT_API(Dos16SetSigHandler)
    LX_NATIVE_MODULE_16BIT_API(Dos16AllocSeg)
    LX_NATIVE_MODULE_16BIT_API(Dos16ReallocSeg)
    LX_NATIVE_MODULE_16BIT_API(Dos16FreeSeg)
    LX_NATIVE_MODULE_16BIT_API(Dos16GetHugeShift)
    LX_NATIVE_MODULE_16BIT_API(Dos16GetMachineMode)
    LX_NATIVE_MODULE_16BIT_API(Dos16Beep)
    LX_NATIVE_MODULE_16BIT_API(Dos16ChDir)
    LX_NATIVE_MODULE_16BIT_API(Dos16ChgFilePtr)
    LX_NATIVE_MODULE_16BIT_API(Dos16Close)
    LX_NATIVE_MODULE_16BIT_API(Dos16Delete)
    LX_NATIVE_MODULE_16BIT_API(Dos16DupHandle)
    LX_NATIVE_MODULE_16BIT_API(Dos16FindClose)
    LX_NATIVE_MODULE_16BIT_API(Dos16FindFirst)
    LX_NATIVE_MODULE_16BIT_API(Dos16FindNext)
    LX_NATIVE_MODULE_16BIT_API(Dos16Open)
    LX_NATIVE_MODULE_16BIT_API(Dos16QCurDir)
    LX_NATIVE_MODULE_16BIT_API(Dos16QCurDisk)
    LX_NATIVE_MODULE_16BIT_API(Dos16QFileMode)
    LX_NATIVE_MODULE_16BIT_API(Dos16QFsInfo)
    LX_NATIVE_MODULE_16BIT_API(Dos16QHandType)
    LX_NATIVE_MODULE_16BIT_API(Dos16SetVec)
    LX_NATIVE_MODULE_16BIT_API(Dos16GetEnv)
    LX_NATIVE_MODULE_16BIT_API(Dos16GetVersion)
    LX_NATIVE_MODULE_16BIT_API(Dos16GetPID)
    LX_NATIVE_MODULE_16BIT_API(Dos16GetCp)
    LX_NATIVE_MODULE_16BIT_API(Dos16Read)
    LX_NATIVE_MODULE_16BIT_API(Dos16Write)
    LX_NATIVE_MODULE_16BIT_API(DosSemRequest)
    LX_NATIVE_MODULE_16BIT_API(DosSemClear)
    LX_NATIVE_MODULE_16BIT_API(DosSemWait)
    LX_NATIVE_MODULE_16BIT_API(DosSemSet)
    LX_NATIVE_MODULE_16BIT_API(Dos16ExecPgm)
LX_NATIVE_MODULE_16BIT_SUPPORT_END()

LX_NATIVE_MODULE_DEINIT({
    LX_NATIVE_MODULE_DEINIT_16BIT_SUPPORT();
})

static int init16_doscalls(void) {
    LX_NATIVE_MODULE_INIT_16BIT_SUPPORT()
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16CWait, 14)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16Exit, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16GetInfoSeg, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16HoldSignal, 2)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16SetSigHandler, 16)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16AllocSeg, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16ReallocSeg, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16FreeSeg, 2)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16GetHugeShift, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16GetMachineMode, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16Beep, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16ChDir, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16ChgFilePtr, 12)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16Close, 2)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16Delete, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16DupHandle, 6)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16FindClose, 2)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16FindFirst, 24)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16FindNext, 12)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16Open, 26)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16QCurDir, 10)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16QCurDisk, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16QFileMode, 12)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16QFsInfo, 10)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16QHandType, 10)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16SetVec, 10)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16GetEnv, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16GetVersion, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16GetPID, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16GetCp, 10)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16Read, 12)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16Write, 12)
        LX_NATIVE_INIT_16BIT_BRIDGE(DosSemRequest, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(DosSemClear, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(DosSemWait, 8)
        LX_NATIVE_INIT_16BIT_BRIDGE(DosSemSet, 4)
        LX_NATIVE_INIT_16BIT_BRIDGE(Dos16ExecPgm, 24)
    LX_NATIVE_MODULE_INIT_16BIT_SUPPORT_END()
    return 1;
}

LX_NATIVE_MODULE_INIT({ if (!init16_doscalls()) return 0; })
    LX_NATIVE_EXPORT16(Dos16CWait, 2),
    LX_NATIVE_EXPORT16(Dos16Exit, 5),
    LX_NATIVE_EXPORT16(Dos16GetInfoSeg, 8),
    LX_NATIVE_EXPORT16(Dos16HoldSignal, 13),
    LX_NATIVE_EXPORT16(Dos16SetSigHandler, 14),
    LX_NATIVE_EXPORT16(Dos16AllocSeg, 34),
    LX_NATIVE_EXPORT16(Dos16ReallocSeg, 38),
    LX_NATIVE_EXPORT16(Dos16FreeSeg, 39),
    LX_NATIVE_EXPORT16(Dos16GetHugeShift, 41),
    LX_NATIVE_EXPORT16(Dos16GetMachineMode, 49),
    LX_NATIVE_EXPORT16(Dos16Beep, 50),
    LX_NATIVE_EXPORT16(Dos16ChDir, 57),
    LX_NATIVE_EXPORT16(Dos16ChgFilePtr, 58),
    LX_NATIVE_EXPORT16(Dos16Close, 59),
    LX_NATIVE_EXPORT16(Dos16Delete, 60),
    LX_NATIVE_EXPORT16(Dos16DupHandle, 61),
    LX_NATIVE_EXPORT16(Dos16FindClose, 63),
    LX_NATIVE_EXPORT16(Dos16FindFirst, 64),
    LX_NATIVE_EXPORT16(Dos16FindNext, 65),
    LX_NATIVE_EXPORT16(Dos16Open, 70),
    LX_NATIVE_EXPORT16(Dos16QCurDir, 71),
    LX_NATIVE_EXPORT16(Dos16QCurDisk, 72),
    LX_NATIVE_EXPORT16(Dos16QFileMode, 75),
    LX_NATIVE_EXPORT16(Dos16QFsInfo, 76),
    LX_NATIVE_EXPORT16(Dos16QHandType, 77),
    LX_NATIVE_EXPORT16(Dos16SetVec, 89),
    LX_NATIVE_EXPORT16(Dos16GetEnv, 91),
    LX_NATIVE_EXPORT16(Dos16GetVersion, 92),
    LX_NATIVE_EXPORT16(Dos16GetPID, 94),
    LX_NATIVE_EXPORT16(Dos16GetCp, 130),
    LX_NATIVE_EXPORT16(Dos16Read, 137),
    LX_NATIVE_EXPORT16(Dos16Write, 138),
    LX_NATIVE_EXPORT16(DosSemRequest, 140),
    LX_NATIVE_EXPORT16(DosSemClear, 141),
    LX_NATIVE_EXPORT16(DosSemWait, 142),
    LX_NATIVE_EXPORT16(DosSemSet, 143),
    LX_NATIVE_EXPORT16(Dos16ExecPgm, 144),
    LX_NATIVE_EXPORT(DosSetMaxFH, 209),
    LX_NATIVE_EXPORT(DosSetPathInfo, 219),
    LX_NATIVE_EXPORT(DosQueryPathInfo, 223),
    LX_NATIVE_EXPORT(DosQueryHType, 224),
    LX_NATIVE_EXPORT(DosScanEnv, 227),
    LX_NATIVE_EXPORT(DosSleep, 229),
    LX_NATIVE_EXPORT(DosGetDateTime, 230),
    LX_NATIVE_EXPORT(DosDevConfig, 231),
    LX_NATIVE_EXPORT(DosExit, 234),
    LX_NATIVE_EXPORT(DosSetPriority, 236),
    LX_NATIVE_EXPORT(DosResetBuffer, 254),
    LX_NATIVE_EXPORT(DosSetCurrentDir, 255),
    LX_NATIVE_EXPORT(DosSetFilePtr, 256),
    LX_NATIVE_EXPORT(DosClose, 257),
    LX_NATIVE_EXPORT(Dos32Copy, 258),
    LX_NATIVE_EXPORT(DosDelete, 259),
    LX_NATIVE_EXPORT(DosDupHandle, 260),
    LX_NATIVE_EXPORT(DosEditName, 261),
    LX_NATIVE_EXPORT(DosFindClose, 263),
    LX_NATIVE_EXPORT(DosFindFirst, 264),
    LX_NATIVE_EXPORT(DosFindNext, 265),
    LX_NATIVE_EXPORT(Dos32Move, 271),
    LX_NATIVE_EXPORT(DosSetFileSize, 272),
    LX_NATIVE_EXPORT(DosOpen, 273),
    LX_NATIVE_EXPORT(DosQueryCurrentDir, 274),
    LX_NATIVE_EXPORT(DosQueryCurrentDisk, 275),
    LX_NATIVE_EXPORT(DosQueryFHState, 276),
    LX_NATIVE_EXPORT(DosQueryFSAttach, 277),
    LX_NATIVE_EXPORT(DosQueryFileInfo, 279),
    LX_NATIVE_EXPORT(DosWaitChild, 280),
    LX_NATIVE_EXPORT(DosRead, 281),
    LX_NATIVE_EXPORT(DosWrite, 282),
    LX_NATIVE_EXPORT(DosExecPgm, 283),
    LX_NATIVE_EXPORT(DosBeep, 286),
    LX_NATIVE_EXPORT(DosSetProcessCp, 289),
    LX_NATIVE_EXPORT(DosQueryCp, 291),
    LX_NATIVE_EXPORT(DosExitList, 296),
    LX_NATIVE_EXPORT(DosAllocMem, 299),
    LX_NATIVE_EXPORT(DosAllocSharedMem, 300),
    LX_NATIVE_EXPORT(DosGetNamedSharedMem, 301),
    LX_NATIVE_EXPORT(DosFreeMem, 304),
    LX_NATIVE_EXPORT(DosSetMem, 305),
    LX_NATIVE_EXPORT(DosQueryMem, 306),
    LX_NATIVE_EXPORT(DosCreateThread, 311),
    LX_NATIVE_EXPORT(DosGetInfoBlocks, 312),
    LX_NATIVE_EXPORT(DosLoadModule, 318),
    LX_NATIVE_EXPORT(DosQueryModuleHandle, 319),
    LX_NATIVE_EXPORT(DosQueryModuleName, 320),
    LX_NATIVE_EXPORT(DosQueryProcAddr, 321),
    LX_NATIVE_EXPORT(DosQueryAppType, 323),
    LX_NATIVE_EXPORT(DosCreateEventSem, 324),
    LX_NATIVE_EXPORT(DosCloseEventSem, 326),
    LX_NATIVE_EXPORT(DosResetEventSem, 327),
    LX_NATIVE_EXPORT(DosPostEventSem, 328),
    LX_NATIVE_EXPORT(DosWaitEventSem, 329),
    LX_NATIVE_EXPORT(DosQueryEventSem, 330),
    LX_NATIVE_EXPORT(DosCreateMutexSem, 331),
    LX_NATIVE_EXPORT(DosCloseMutexSem, 333),
    LX_NATIVE_EXPORT(DosRequestMutexSem, 334),
    LX_NATIVE_EXPORT(DosReleaseMutexSem, 335),
    LX_NATIVE_EXPORT(DosSubSetMem, 344),
    LX_NATIVE_EXPORT(DosSubAllocMem, 345),
    LX_NATIVE_EXPORT(DosSubFreeMem, 346),
    LX_NATIVE_EXPORT(DosQuerySysInfo, 348),
    LX_NATIVE_EXPORT(DosWaitThread, 349),
    LX_NATIVE_EXPORT(DosSetExceptionHandler, 354),
    LX_NATIVE_EXPORT(DosUnsetExceptionHandler, 355),
    LX_NATIVE_EXPORT(DosQuerySysState, 368),
    LX_NATIVE_EXPORT(DosSetSignalExceptionFocus, 378),
    LX_NATIVE_EXPORT(DosEnterMustComplete, 380),
    LX_NATIVE_EXPORT(DosExitMustComplete, 381),
    LX_NATIVE_EXPORT(DosSetRelMaxFH, 382),
    LX_NATIVE_EXPORT(DosFlatToSel, 425),
    LX_NATIVE_EXPORT(DosSelToFlat, 426),
    LX_NATIVE_EXPORT(Dos32CancelLockRequest, 429),
    LX_NATIVE_EXPORT(DosAllocThreadLocalMemory, 454),
    LX_NATIVE_EXPORT(DosFreeThreadLocalMemory, 455),
    LX_NATIVE_EXPORT(DosR3ExitAddr, 553),
    LX_NATIVE_EXPORT(DosSetFilePtrL, 568),
    LX_NATIVE_EXPORT(DosQueryHeaderInfo, 582),
    LX_NATIVE_EXPORT(DosQueryExtLIBPATH, 874),
    LX_NATIVE_EXPORT(DosQueryThreadContext, 877),
    LX_NATIVE_EXPORT(DosOpenL, 981),
    LX_NATIVE_EXPORT(Dos32CancelLockRequestL, 987)
LX_NATIVE_MODULE_INIT_END()

#endif /* LX_LEGACY */

/* end of doscalls-lx.h ... */

