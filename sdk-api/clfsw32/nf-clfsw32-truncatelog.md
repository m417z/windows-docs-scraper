# TruncateLog function

## Description

Truncates the log. The function sets the end of the log to the specified value.

## Parameters

### `pvMarshal` [in]

A pointer to the opaque marshaling context that is allocated by calling the [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) function.

### `plsnEnd` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the new end of a log.

The LSN must be between the base log sequence number (LSN) of the log and the last LSN of the log.

### `lpOverlapped` [in, out, optional]

Reserved. Set *Reserved* to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## Remarks

If the volume sector size is greater than 512 bytes, **TruncateLog** returns ERROR_NOT_SUPPORTED.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)