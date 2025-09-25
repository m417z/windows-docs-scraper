# ClfsCreateScanContext function

## Description

The **ClfsCreateScanContext** routine creates a scan context that can be used to iterate over the containers of a specified CLFS log.

## Parameters

### `plfoLog` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS stream. The scan context is created for the log that provides the underlying storage for that stream. The caller previously obtained this pointer by calling [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile).

### `cFromContainer` [in]

The index of the first container to be scanned. Containers are indexed starting at zero.

### `cContainers` [in]

The number of containers to be scanned with each call to [ClfsScanLogContainers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsscanlogcontainers).

### `eScanMode` [in]

 A set of flags that specify whether the scan context is set up for scanning forward or backward and whether the scan context should be reinitialized. The following three flags are available for callers of this routine.

| Value | Meaning |
| --- | --- |
| CLFS_SCAN_FORWARD | Set up the scan context for scanning in the forward direction. For example, if container 5 is the most recently scanned container and *cContainers* is 2, then a forward scan would return descriptors for containers 6 and 7. |
| CLFS_SCAN_BACKWARD | Set up the scan context for scanning in the backward direction. For example, if container 5 is the most recently scanned container and *cContainers* is 2, then a backward scan would return descriptors for containers 4 and 3. |
| CLFS_SCAN_INIT | Reinitialize the scan context. The next time **ClfsScanLogContainers** is called, it will behave as if it were being called for the first time after the creation of the scan context. |

If *pcxScan* points to a CLFS_SCAN_CONTEXT structure that is being passed to this routine for the first time, one of the direction flags (CLFS_SCAN_FORWARD or CLFS_SCAN_BACKWARD) must be set. The CLFS_SCAN_INIT flag must not be set.

If *pcxScan* points to a CLFS_SCAN_CONTEXT structure that has been passed to this routine previously, the CLFS_SCAN_INIT flag must be set. Also, one and only one of the direction flags (CLFS_SCAN_FORWARD or CLFS_SCAN_BACKWARD) must be set.

### `pcxScan` [in, out]

A pointer to a caller-allocated [CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_scan_context) structure whose members are initialized by this routine. This structure is later passed to [ClfsScanLogContainers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsscanlogcontainers).

## Return value

**ClfsCreateScanContext** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsScanLogContainers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsscanlogcontainers)