# WER_RUNTIME_EXCEPTION_INFORMATION structure

## Description

Contains the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) exception information used to determine whether you want to claim the crash.

## Members

### `dwSize`

Size, in bytes, of this structure.

### `hProcess`

The handle to the process that crashed.

### `hThread`

The handle to the thread that crashed.

### `exceptionRecord`

An [EXCEPTION_RECORD](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) structure that contains the exception information.

### `context`

A [CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that contains the context information.

### `pwszReportId`

A pointer to a constant, null-terminated string that contains the size of the exception information.

## See also

[OutOfProcessExceptionEventCallback](https://learn.microsoft.com/windows/desktop/api/werapi/nc-werapi-pfn_wer_runtime_exception_event), [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/)