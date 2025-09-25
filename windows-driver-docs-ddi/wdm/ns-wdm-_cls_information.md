# _CLS_INFORMATION structure

## Description

The **CLFS_INFORMATION** structure holds metadata and state information for a Common Log File System (CLFS) stream and/or its underlying physical log.

## Members

### `TotalAvailable`

The total available space allocated to the log. This is calculated as the sum of the sizes of all containers in the log.

### `CurrentAvailable`

The amount of space available in the log for new records and reservation allocations. This space is the total available space minus the undo commitment space and space used for storing owner pages in a multiplexed log.

### `TotalReservation`

The amount of space reserved in the stream (or physical log) for undo operations.

### `BaseFileSize`

The size, in bytes, of the base log file.

### `ContainerSize`

The size, in bytes, of an individual container in the log. Note that all containers in the log are the same size.

### `TotalContainers`

The number of containers in the log.

### `FreeContainers`

The number of containers in the log that are not active.

### `TotalClients`

The number of streams that share the log.

### `Attributes`

A set of flags that specify stream (or physical log) attributes. See the *fFlagsAndAttributes* parameter of the [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile) function.

### `FlushThreshold`

The number of bytes of data (including headers) that are allowed to remain pending on the internal flush queue before CLFS automatically schedules a thread to write the flush queue to stable storage.

### `SectorSize`

The sector size, in bytes, of the underlying disk geometry. The sector size is assumed to be a multiple of 512 and consistent across containers.

### `MinArchiveTailLsn`

The LSN of the oldest record in the log for which archiving has not taken place. The minimum of this and the base LSN determines the last container that can be reused when containers are recycled.

### `BaseLsn`

The LSN of the oldest record in the stream (or physical log) that is still needed by the stream (or log) clients.

### `LastFlushedLsn`

The LSN of the last record that was flushed to stable storage.

### `LastLsn`

The LSN of the youngest record in the stream (or physical log) that is still needed by the stream (or log) clients.

### `RestartLsn`

The LSN of the last restart record written to the stream (or physical log). If there are no restart records, this member is equal to CLFS_LSN_INVALID.

### `Identity`

A GUID that serves as a unique identifier for the log.

## Remarks

The [ClfsQueryLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsquerylogfileinformation) function returns information about a CLFS stream and/or its underlying physical log. The type of information returned depends on the *eInformationClass* parameter.

If the *eInformationClass* parameter is equal to **ClfsLogBasicInformationPhysical**, **ClfsQueryLogFileInformation** returns information in a **CLFS_INFORMATION** structure, and every structure member holds a piece of information about a physical CLFS log. Even if the log is multiplexed (that is, it has several streams), all structure members hold information about the underlying physical log rather than information about one of the streams.

If *eInformationClass* parameter is equal to **ClfsLogBasicInformation**, **ClfsQueryLogFileInformation** returns information in a **CLFS_INFORMATION** structure. Most of the structure members hold information about a CLFS physical log, but if the log is multiplexed, certain members hold information that is specific to a particular stream. The following structure members hold information that is specific to a stream rather than the underlying physical log:

* **TotalUndoCommitment**
* **Attributes**
* **BaseLsn**
* **LastLsn**
* **RestartLsn**

## See also

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsQueryLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsquerylogfileinformation)

[ClfsSetLogFileInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfssetlogfileinformation)