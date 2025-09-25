# CLS_INFORMATION structure

## Description

Describes general information about a log. The [GetLogFileInformation](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogfileinformation) function returns the **CLFS_INFORMATION** structure.

## Members

### `TotalAvailable`

The total available space that is allocated to a log, in bytes.

This member is the sum of the sizes of all containers that are allocated to the dedicated log.

### `CurrentAvailable`

The space that is available in a log to append new records and reservation allocations, in bytes.

### `TotalReservation`

The total space in a log that is dedicated to reservation allocations.

### `BaseFileSize`

The size of the base log, in bytes.

### `ContainerSize`

The size of a container, in bytes.

### `TotalContainers`

The number of active containers that are associated with a dedicated log.

### `FreeContainers`

The number of containers that are not in an active log.

### `TotalClients`

The number of log streams that are active in a physical log.

### `Attributes`

The log attributes that are set by using the *fFlagsAndAttributes* parameter of [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) when a log is created.

### `FlushThreshold`

The number of bytes of data that can remain pending on the internal flush queue before the Common Log File System (CLFS) automatically writes the data to disk.

### `SectorSize`

The sector size of the underlying disk geometry, in bytes.

The sector size is assumed to be a multiple of 512 and consistent across log containers.

### `MinArchiveTailLsn`

The log sequence number (LSN) of the log archive tail.

### `BaseLsn`

The LSN that marks the start of the active region of a log.

### `LastFlushedLsn`

The value of **LastFlushedLsn** indicates that any LSNs smaller than the one specified are already flushed to disk.

### `LastLsn`

The value of **LastLsn** indicates that any LSNs smaller than the one specified are already appended to the log.

### `RestartLsn`

The LSN of the last written restart record.

If the log does not have a restart area, the LSN has the value of CLFS_LSN_INVALID.

### `Identity`

The unique identifier for a log.

## See also

[GetLogFileInformation](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogfileinformation)