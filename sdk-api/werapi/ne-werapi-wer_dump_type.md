# WER_DUMP_TYPE enumeration

## Description

Defines the possible [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) [minidump](https://learn.microsoft.com/windows/desktop/Debug/minidump-files) types.

## Constants

### `WerDumpTypeNone`

No dump.

### `WerDumpTypeMicroDump`

A limited minidump that contains only a stack trace. This type is equivalent to creating a minidump with the following options:

- MiniDumpWithDataSegs
- MiniDumpWithUnloadedModules
- MiniDumpWithProcessThreadData
- MiniDumpWithoutOptionalData

### `WerDumpTypeMiniDump`

A minidump. This type is equivalent to creating a minidump with the following options:

- MiniDumpWithDataSegs
- MiniDumpWithUnloadedModules
- MiniDumpWithProcessThreadData
- MiniDumpWithTokenInformation (Windows 7 and later)

### `WerDumpTypeHeapDump`

An extended minidump that contains additional data such as the process memory. This type is equivalent to creating a minidump with the following options:

- MiniDumpWithDataSegs
- MiniDumpWithProcessThreadData
- MiniDumpWithHandleData
- MiniDumpWithPrivateReadWriteMemory
- MiniDumpWithUnloadedModules
- MiniDumpWithFullMemoryInfo
- MiniDumpWithThreadInfo (Windows 7 and later)
- MiniDumpWithTokenInformation (Windows 7 and later)
- MiniDumpWithPrivateWriteCopyMemory (Windows 7 and later)

### `WerDumpTypeTriageDump`

An extended minidump that contains additional data for triage purposes.

### `WerDumpTypeMax`

An extended minidump that contains all saved data.

## Remarks

## See also

[WerReportAddDump function](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werreportadddump), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)