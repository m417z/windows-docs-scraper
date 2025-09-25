# ClfsScanLogContainers function

## Description

The **ClfsScanLogContainers** routine retrieves descriptive information for a sequence of containers that belong to a particular CLFS log.

## Parameters

### `pcxScan` [in, out]

A pointer to a [CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_scan_context) structure. The caller previously allocated the structure and initialized it by calling [ClfsCreateScanContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatescancontext). In particular, the **pInfoContainer** member was initialized to point to an array of [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_container_information) structures, and the **cContainers** member was initialized to the number of elements in the array. On return, the structures in the array receive descriptive information for the containers in the sequence.

### `eScanMode` [in]

A set of flags that specify the direction of the scan and whether the scan context should be closed. The following flags are available to callers of this routine.

| Value | Meaning |
| --- | --- |
| CLFS_SCAN_FORWARD | Scan in the forward direction. For example, if container 5 is the most recently scanned container and *pxcScan*->**cContainers** is equal to two, this routine will return descriptors for containers 6 and 7. |
| CLFS_SCAN_BACKWARD | Scan in the backward direction. For example, if container 5 is the most recently scanned container and *pxcScan*->**cContainers** is equal to two, this routine will return descriptors for containers 4 and 3. |
| CLFS_SCAN_CLOSE | Free all resources associated with the scan context pointed to by *pcxScan*. |

If the CLFS_SCAN_CLOSE flag is set, both the CLFS_SCAN_FORWARD and CLFS_SCAN_BACKWARD flags must be clear.

If the CLFS_SCAN_CLOSE flag is clear, only one of the direction flags (CLFS_SCAN_FORWARD or CLFS_SCAN_BACKWARD) must be set.

## Return value

**ClfsScanLogContainers** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

CLFS uses the [CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_scan_context) structure to track where a container scan starts (the **cIndex** member) and how many containers are scanned in each call to **ClfsScanLogContainers**. The value N of the **cContainers** member specifies that each time **ClfsScanLogContainers** is called, the next N containers are scanned.

The **cContainersReturned** member of the **CLFS_SCAN_CONTEXT** structure receives the number of containers actually scanned in a single call to **ClfsScanLogContainers**.

When **ClfsScanLogContainers** returns STATUS_NO_MORE_ENTRIES, there are no more containers to be scanned.

When you have finished using the scan context pointed to by *pcxScan*, you must call **ClfsScanLogContainers**, with *eScanMode* equal to CLFS_SCAN_CLOSE, to free any resources associated with the scan context.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_container_information)

[CLFS_SCAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_scan_context)

[ClfsCreateScanContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatescancontext)