# WER_EXCEPTION_INFORMATION structure

## Description

Contains [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) exception information for the [WerReportAddDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportadddump) function.

## Members

### `pExceptionPointers`

A pointer to an [EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers) structure.

### `bClientPointers`

A process (calling process) can provide error reporting functionality for another process (client process). If this member is **TRUE**, the exception pointer is located inside the address space of the client process. If this member is **FALSE**, the exception pointer is located inside the address space of the calling process.

## See also

[WerReportAddDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werreportadddump), [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/)