# ScanLogContainers function

## Description

Enumerates log containers. Call this function repeatedly to iterate over all log containers.

## Parameters

### `pcxScan` [in, out]

A pointer to a client-allocated [CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows/win32/api/clfs/ns-clfs-cls_scan_context~r1) structure that the [CreateLogContainerScanContext](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogcontainerscancontext) function initializes.

### `eScanMode` [in]

The mode for containers to be scanned.

Containers can be scanned in any of the following [CLFS_SCAN_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-scan-mode-constants) modes.

| Value | Meaning |
| --- | --- |
| **CLFS_SCAN_INIT** | Reinitializes the scan context, but does not allocate associated storage. <br><br>The initialization is destructive, because all data that is stored in the current scan context is lost. |
| **CLFS_SCAN_CLOSE** | Uninitializes the scan context, and deallocates system storage that is associated with a scan context. |
| **CLFS_SCAN_FORWARD** | Causes the next call to **ScanLogContainers** to proceed in a forward direction. <br><br>Cannot be used if **CLFS_SCAN_BACKWARD** is specified. |
| **CLFS_SCAN_BACKWARD** | Causes the next call to **ScanLogContainers** to proceed in a backward direction. <br><br>Cannot be used if **CLFS_SCAN_FORWARD** is specified. |

### `pReserved` [in, out, optional]

Reserved. Set *pReserved* to **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

 The following list identifies the possible error codes:

## Remarks

The ID of a log container is returned in: **pcxScan->pinfoContainer->LogicalContainerId**.

**Note** The Common Log File System (CLFS) scan contexts are not thread-safe. They should not be used by more than one thread at a time, or passed into more than one asynchronous scan at a time.

#### Examples

For an example that uses this function, see [Enumerating Log Containers](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/enumerating-log-containers).

## See also

[CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows/win32/api/clfs/ns-clfs-cls_scan_context~r1)

[CLFS_SCAN_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/clfs-scan-mode-constants)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogContainerScanContext](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogcontainerscancontext)

[GetLogContainerName](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getlogcontainername)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)