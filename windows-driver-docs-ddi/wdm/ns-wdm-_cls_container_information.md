# _CLS_CONTAINER_INFORMATION structure

## Description

The **CLFS_CONTAINER_INFORMATION** structure holds descriptive information for an individual container in a Common Log File System (CLFS) log.

## Members

### `FileAttributes`

A set of flags that specifies attributes of the container. See the *fFlagsAndAttributes* parameter of the [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile) function.

### `CreationTime`

The time that the container was created.

### `LastAccessTime`

The time that the container was last accessed.

### `LastWriteTime`

The time of the last write to the container.

### `ContainerSize`

The size, in bytes, of the container.

### `FileNameActualLength`

The size, in characters, of the actual file name of the container.

### `FileNameLength`

The size of the file name in the **FileName** buffer.

### `FileName`

An array of wide characters that holds the file name of the container.

### `State`

An integer that specifies the state of the container. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **ClfsContainerInitializing** | The container has not yet been initialized. |
| **ClfsContainerInactive** | The container has been initialized but does not hold any records that are in the active portion of the log. |
| **ClfsContainerActive** | The container is being used to hold records that belong to the active portion of the log. |
| **ClfsContainerActivePendingDelete** | The container is marked for deletion, but still holds records that belong to the active portion of the log. |
| **ClfsContainerPendingArchive** | The container is pending archival. |
| **ClfsContainerPendingArchiveAndDelete** | The container is marked for deletion, but still contains records that are pending archival. |

### `PhysicalContainerId`

A 32-bit identifier that remains the same over the life of the log.

### `LogicalContainerId`

A 32-bit identifier that changes every time the container is recycled.

## Remarks

The [ClfsScanLogContainers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsscanlogcontainers) function writes descriptive information into an array of **CLFS_CONTAINER_INFORMATION** structures.

Time values **CreationTime**, **LastAccessTime**, and **LastWriteTime** are expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar.

## See also

[CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_scan_context)

[ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile)

[ClfsCreateScanContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatescancontext)

[ClfsScanLogContainers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsscanlogcontainers)