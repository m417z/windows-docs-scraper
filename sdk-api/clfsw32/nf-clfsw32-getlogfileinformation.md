# GetLogFileInformation function

## Description

Returns a buffer that contains metadata about a specified log and its current state, which is defined by the [CLFS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_information) structure.

Data that is obtained reflects the state of the log only at the time when the call is made. Typically, a client can continue to cache and use fields from this structure until the next time that it appends records or writes its restart area. At that time, some of the information becomes stale.

## Parameters

### `hLog` [in]

A handle to an open log that is obtained from a successful call to [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

The log handle can refer to a dedicated or multiplexed log.

### `pinfoBuffer` [in, out]

A pointer to a user-allocated [CLFS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_information) structure that receives the log metadata.

### `cbBuffer` [in, out]

A pointer to a variable that on input specifies the size, in bytes, of the metadata buffer pointed to by *pinfoBuffer*.

 On output, it specifies the number of bytes that are actually copied into *pinfoBuffer*.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

 The following list identifies the possible error codes:

## See also

[CLFS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_information)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile)

[Obtaining the Next LSN](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/obtaining-the-next-lsn)