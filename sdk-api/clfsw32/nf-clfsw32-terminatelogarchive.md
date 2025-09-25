# TerminateLogArchive function

## Description

Deallocates system resources that are allocated originally for a log archive context by [PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive).

## Parameters

### `pvArchiveContext` [in]

The archive context that is obtained from [PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following error code is possible:

## Remarks

Failure to call this function after archiving completes results in a resource leak.

## See also

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive)