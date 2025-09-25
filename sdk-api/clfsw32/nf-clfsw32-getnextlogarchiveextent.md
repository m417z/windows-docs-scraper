# GetNextLogArchiveExtent function

## Description

Retrieves the next set of archive extents in a log archive context. The log archive context describes a contiguous set of file extents that span the snapshot of the active log captured by [PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive) captures. **GetNextLogArchiveExtent** maintains a cursor in the ordered set of log archive descriptors so that subsequent calls allow an application to iterate through the entire set.

## Parameters

### `pvArchiveContext` [in]

A pointer to an archive context that is obtained by a call to [PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive).

 The context maintains the cursor state, which allows iteration through the set of file extents in the archive. The archive client is responsible for deallocating the context by using the [TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive) function.

### `rgadExtent` [in, out]

A client-allocated array of [CLFS_ARCHIVE_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_archive_descriptor) structures to be filled in by this function.

### `cDescriptors` [in]

The number of elements in the *rgadExtent* array.

This value is the maximum number of archive descriptors that can be retrieved by this function.

### `pcDescriptorsReturned` [out]

The number of descriptors in the *rgadExtent* array that are filled in by this function.

If this value is less than *cDescriptors*, the set of descriptors is exhausted and the archive client can terminate iteration through the ordered descriptor set. Further calls to this function fail with ERROR_NO_MORE_ENTRIES.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following list identifies the possible error codes:

## See also

[CLFS_ARCHIVE_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_archive_descriptor)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)