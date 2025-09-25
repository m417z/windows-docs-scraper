# CreateLogContainerScanContext function

## Description

Creates a scan context to use with [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) to enumerate all log containers that are associated with a log, and performs the first scan.

## Parameters

### `hLog` [in]

A handle to the log that is obtained from [CreateLogFile](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogfile) with permissions to scan the log containers.

The file can be a dedicated or multiplexed log.

### `cFromContainer` [in]

The container where the scan is to be started.

This parameter is an ordinal number relative to the number of containers in the log.

### `cContainers` [in]

The number of [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information) structures for **CreateLogContainerScanContext** to allocate.

This number is the number of containers scanned with each scan call so the caller knows the scan is complete when the number of containers returned is less than this value.

On exit, a pointer to the system-allocated array of [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information) structures is placed in the **pinfoContainer** member of the client-allocated [CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows/win32/api/clfs/ns-clfs-cls_scan_context~r1) structure. This member is pointed to by the *pcxScan* parameter (that is, "pcxScan->pinfoContainer[]"), and the actual number of structures in the array is placed in "pcxScan->cContainersReturned".

The client must call [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) with the *eScanMode* parameter set to **CLFS_SCAN_CLOSE** so that it can free this array; otherwise, memory leaks result.

### `eScanMode` [in]

The mode to scan containers.

Containers can be scanned in any one of the following modes.

| Value | Meaning |
| --- | --- |
| **CLFS_SCAN_INIT** | Initializes or reinitializes a scan from the first container in the container list. <br><br>This mode initializes the container context and returns the first set of container descriptors that *cContainers* specifies. |
| **CLFS_SCAN_FORWARD** | Returns the first set of containers that *cContainers* specifies. |
| **CLFS_SCAN_BACKWARD** | Returns the last set of containers that *cContainers* specifies. |

### `pcxScan` [in, out]

A pointer to a client-allocated [CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows/win32/api/clfs/ns-clfs-cls_scan_context~r1) structure that receives a scan context that can be passed to the [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) function when a client scans the log containers of a dedicated log.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is required for asynchronous operation.

This parameter can be **NULL** if an asynchronous operation is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

After completing a scan, the client must call [ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers) again with the *eScanMode* parameter set to **CLFS_SCAN_CLOSE** so that it can free the system-allocated array of [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information) structures; otherwise, memory leaks result.

#### Examples

For an example that uses this function, see [Enumerating Log Containers](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/enumerating-log-containers).

## See also

[CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information)

[CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows/win32/api/clfs/ns-clfs-cls_scan_context~r1)

[CLFS_SCAN_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-scan-mode-constants)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[ScanLogContainers](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-scanlogcontainers)