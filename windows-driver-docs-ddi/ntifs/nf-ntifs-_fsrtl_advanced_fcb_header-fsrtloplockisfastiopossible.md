# FsRtlOplockIsFastIoPossible function

## Description

**FsRtlOplockIsFastIoPossible** checks a file's opportunistic lock (oplock) state to determine whether fast I/O can be performed on the file.

## Parameters

### `Oplock` [in]

Opaque opportunistic lock pointer for the file. This pointer must have been initialized by a previous call to [**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

## Return value

**FsRtlOplockIsFastIoPossible** returns FALSE if there are outstanding opportunistic locks on the file that prevent fast I/O from being performed; TRUE otherwise.

## Remarks

**FsRtlOplockIsFastIoPossible** determines whether fast I/O can be performed on a file, according to the following conditions:

* If the **Oplock** parameter is NULL, or if the value of **Oplock* is NULL, there are no outstanding opportunistic locks on the file, and fast I/O can be performed on the file.

* If an exclusive opportunistic lock was granted for the file, but no oplock break is in progress, fast I/O can be performed on the file.

For detailed information about opportunistic locks, see the Windows SDK documentation.

Minifilters should call [**FltOplockIsFastIoPossible**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockisfastiopossible) instead of **FsRtlOplockIsFastIoPossible**.

## See also

[FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[FSCTL_OPLOCK_BREAK_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[**FltOplockIsFastIoPossible**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockisfastiopossible)

[**FsRtlCheckOplock**](https://learn.microsoft.com/windows/win32/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[**FsRtlCurrentBatchOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcurrentbatchoplock)

[**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)

[**FsRtlOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[**FsRtlUninitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializeoplock)