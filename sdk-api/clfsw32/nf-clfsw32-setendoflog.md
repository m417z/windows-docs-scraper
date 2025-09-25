# SetEndOfLog function

## Description

This function has been deprecated. Use [TruncateLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-truncatelog) instead.

## Parameters

### `hLog` [in]

 A handle to the log that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

The log handle must refer to a dedicated log.

### `plsnEnd` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the new end of a log.

The LSN must be between the base log sequence number (LSN) of the log and the last LSN of the log.

### `lpOverlapped` [in, out, optional]

Reserved. Set *lpOverlapped* to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## Remarks

The **SetEndOfLog** function truncates the log by setting the end of the log to the specified value. This operation only works on dedicated logs.

**SetEndOfLog** can only be used to truncate a log.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)