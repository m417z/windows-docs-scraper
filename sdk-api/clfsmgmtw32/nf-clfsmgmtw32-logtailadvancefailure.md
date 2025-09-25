# LogTailAdvanceFailure function

## Description

The **LogTailAdvanceFailure** function is
called by a log client to indicate that it cannot comply with a request from log management to advance its
tail.

## Parameters

### `hLog` [in]

A handle to the log on which to resolve the log full condition.

### `dwReason` [in]

Win32 error code with the reason for the failure For a list of possible values, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Valid values include the following:

## See also

[CLFS Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-management-functions)