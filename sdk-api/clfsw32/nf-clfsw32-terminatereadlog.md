# TerminateReadLog function

## Description

Terminates a read context. This function frees system-allocated resources associated with the specified read context. Do not attempt to read log records after calling this function; you will receive indeterminate results.

## Parameters

### `pvCursorContext` [in]

A pointer to a read context that is returned by [ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord) or [ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## Remarks

It is important to deallocate unused read contexts. Failure to call this function causes resource leaks.

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[ReadLogRecord](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrecord)

[ReadLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogrestartarea)