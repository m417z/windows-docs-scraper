# CLS_CONTAINER_INFORMATION structure

## Description

Describes general information about a container. The [CreateLogContainerScanContext](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogcontainerscancontext) and [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) functions use container descriptors to scan and return information about all Common Log File System (CLFS) containers.

## Members

### `FileAttributes`

The file system attributes. CLFS uses the following attributes:

* FILE_ATTRIBUTE_ARCHIVE - The log is not ephemeral.
* FILE_ATTRIBUTE_DEDICATED - The log is not multiplexed.
* FILE_ATTRIBUTE_READONLY - The file is read-only. Applications can read the file, but cannot write to it or delete it.

CLFS ignores but preserves all other file attribute values. The [SetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileattributesa) topic lists the valid values for attributes.

### `CreationTime`

The time a file is created.

### `LastAccessTime`

The last time a container is read from or written to.

### `LastWriteTime`

The last time a container is written to.

### `ContainerSize`

The size of a container, in bytes.

### `FileNameActualLength`

The size of the actual file name, in characters.

This number is different than **FileNameLength** when the file name of the container is longer than MAX_PATH_LENGTH.

### `FileNameLength`

The size of the file name in the *FileName* buffer, in characters.

### `FileName`

A pointer to a string that contains the file name for a container.

### `State`

The current state of a container.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ClfsContainerInitializing** | The container is in the process of initializing. |
| **ClfsContainerInactive** | The container is allocated, but is not in the active region of the log. |
| **ClfsContainerActive** | The container is being used as storage for part of the log. |
| **ClfsContainerActivePendingDelete** | The container is marked for deletion, but still contains part of the active log. |
| **ClfsContainerPendingArchive** | The container is marked for archive. |
| **ClfsContainerPendingArchiveAndDelete** | The container is marked for deletion, but still contains log data that is not archived. |

### `PhysicalContainerId`

The physical container identifier that cannot be changed.

### `LogicalContainerId`

The logical container identifier that changes every time the container is recycled.

## See also

[CreateLogContainerScanContext](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogcontainerscancontext)

[GetLogContainerName](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogcontainername)

[ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers)