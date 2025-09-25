# PrepareLogArchive function

## Description

Prepares a physical log for archival. The function takes a snapshot of the current active log, builds an ordered set of log archive descriptors for the active log extents, and returns a log archive context.

 By passing this log archive context to [GetNextLogArchiveExtent](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getnextlogarchiveextent), a client can iterate through the set of log archive extents to archive the log. You can also specify a range of records to archive.

## Parameters

### `hLog` [in]

A handle to the log that is obtained by a successful call to [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

This handle can be the handle to a dedicated or multiplexed log.

### `pszBaseLogFileName` [in, out]

A pointer to a user-allocated buffer to receive the fully qualified path of the base log.

If the buffer is not large enough, it contains a truncated file path on exit, and the function fails with an *ERROR_BUFFER_OVERFLOW* status code.

The length of the file path is returned in the variable pointed to by *pcActualLength*. The client can re-attempt a failed call with a name buffer that is large enough.

### `cLen` [in]

The size of the *pszBaseLogFileName* buffer, in wide characters.

### `plsnLow` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the log sequence number (LSN) of the low end of the range of the active log where the log client needs log archival information.

If this parameter is omitted, the low end of the range defaults to the LSN of the log archive tail.

### `plsnHigh` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies the LSN of the high end of the range of the active log where the log client needs log archival information.

If this parameter is omitted, the high end of the range defaults to the next LSN to be written to the log.

### `pcActualLength` [out, optional]

A pointer to a variable that receives the actual length of the name of the base log path, in characters.

If this value is greater than *cLen*, the function returns an ERROR_BUFFER_OVERFLOW status with a truncated path that is stored in the *pszBaseLogFileName* buffer and all other out parameters that are not set to meaningful values.

### `poffBaseLogFileData` [out]

A pointer to a variable that receives the offset where the metadata begins in the base log.

The contiguous extent in the base log *pszBaseLogFileName* represents the full contents of the log metadata—that is, from *poffBaseLogFileData* to *pcbBaseLogFileLength*.

### `pcbBaseLogFileLength` [out]

A pointer to a variable that specifies the exact length of the base log, in bytes.

### `plsnBase` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to receive the base log sequence number (LSN) of the active log.

### `plsnLast` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to receive the highest valid LSN in the active log.

### `plsnCurrentArchiveTail` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure to receive the current LSN of the archive tail of the log.

### `ppvArchiveContext` [out]

A pointer to the variable that receives a pointer to an archive context that the system allocates.

The archive context maintains the cursor state of the archival iterator and the log handle context. The archival client is responsible for releasing the context by calling [TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## Remarks

You must call [TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive) to free the archive context, or memory leaks can occur.

Until you call [TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive), containers that are being archived cannot be recycled.

You can only perform one archive operation at a time per handle that [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) returns.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[GetNextLogArchiveExtent](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getnextlogarchiveextent)

[ReadLogArchiveMetadata](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-readlogarchivemetadata)

[TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive)