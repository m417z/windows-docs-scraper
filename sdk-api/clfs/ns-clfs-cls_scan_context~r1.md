# CLS_SCAN_CONTEXT structure

## Description

Contains information about the containers that are being scanned by [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers), the kind of scan that is being performed, and a cursor to track which containers have been scanned.

## Members

### `cidNode`

The ID of the current node. For more information, see [CLFS_NODE_ID](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-clfs_node_id).

### `hLog`

A handle to the log being scanned that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) with permissions to scan the log containers.

### `cIndex`

The index of the current container.

### `cContainers`

The number of system-allocated [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information) structures in an array that is pointed to by **pinfoContainer**.

That is, this member is the number of containers to scan with each scan call. The caller knows the scan is complete when the number of containers returned is less than this value.

### `cContainersReturned`

The number of containers that are returned after a call to [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers).

### `eScanMode`

The mode in which containers are scanned.

Containers can be scanned in one of the following modes.

| Value | Meaning |
| --- | --- |
| **CLFS_SCAN_INIT** | Initializes the scan context, but does not allocate associated storage. <br><br>The initialization is destructive, because all data that is stored in the current scan context is lost. |
| **CLFS_SCAN_CLOSE** | Uninitializes the scan context and deallocates system storage that is associated with a scan context. |
| **CLFS_SCAN_FORWARD** | Causes the next call to [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) to proceed in a forward direction. <br><br>Cannot be used if **CLFS_SCAN_BACKWARD** is specified. |
| **CLFS_SCAN_BACKWARD** | Causes the next call to [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) to proceed in a backward direction. <br><br>Cannot be used if **CLFS_SCAN_FORWARD** is specified. |

### `pinfoContainer`

A pointer to
a client-allocated array of [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information) structures to be filled by [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) after each successful call.

## Remarks

This structure is allocated by the client, initialized using [CreateLogContainerScanContext](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogcontainerscancontext), and then passed to [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) in repeated calls.

## See also

[CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information)

[CLFS_NODE_ID](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-clfs_node_id)

[ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers)