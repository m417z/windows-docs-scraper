# ReadLogArchiveMetadata function

## Description

Copies a range of the archive view of the metadata to the specified buffer.

## Parameters

### `pvArchiveContext` [in]

A pointer to an archive context that is obtained by a call to [PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive).

 The context maintains the cursor state, which allows iteration through the set of file extents in the archive. The archive client is responsible for deallocating the context by using the [TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive) function.

### `cbOffset` [in]

The offset in the metadata where data copying starts.

On the first call to this function, specify zero (0). On subsequent calls, specify the value that is returned in *pcbBytesRead*.

### `cbBytesToRead` [in]

The number of bytes of the metadata snapshot should be copied into *pbReadBuffer*.

This parameter cannot be zero (0).

### `pbReadBuffer` [in, out]

A pointer to the buffer where the metadata snapshot is copied.

### `pcbBytesRead` [out]

A pointer to a variable that receives the number of bytes that are copied to *pbReadBuffer*.

The number of bytes is always between zero (0) and *cbBytesToRead*.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive)

[TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive)