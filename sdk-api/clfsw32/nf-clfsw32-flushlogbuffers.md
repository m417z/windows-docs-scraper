# FlushLogBuffers function

## Description

Forces all records appended to this marshaling area to be flushed to disk. This service is a special case of [FlushLogToLsn](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-flushlogtolsn) with the target log sequence number (LSN) set to **CLFS_LSN_NULL**.

## Parameters

### `pvMarshal` [in]

A pointer to the marshaling context that is allocated by using the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is required for asynchronous operation.

This parameter can be **NULL** if asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[FlushLogToLsn](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-flushlogtolsn)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)