# SetLogArchiveTail function

## Description

Sets the last archived log sequence number (LSN) or *archive tail* of an archivable log.

## Parameters

### `hLog` [in]

A handle to the log that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile).

The log handle can refer to a dedicated or multiplexed log.

### `plsnArchiveTail` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that specifies a valid physical LSN in the log.

**Note** For handles to both a physical log or a log stream, *plsnArchiveTail* is a physical LSN, because it refers to a record address in the physical log.

### `pReserved` [in, out, optional]

This parameter is reserved and should be set to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

If there are any archive contexts obtained from [PrepareLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-preparelogarchive) that are not terminated with [TerminateLogArchive](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-terminatelogarchive), the change does not take effect until all archives are complete. While there are outstanding archive contexts, only the greatest archive tail is applied.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[RemoveLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-removelogcontainer)

[RemoveLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-removelogcontainerset)