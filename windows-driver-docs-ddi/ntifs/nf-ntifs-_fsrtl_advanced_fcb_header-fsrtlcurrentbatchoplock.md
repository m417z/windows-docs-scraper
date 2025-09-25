# FsRtlCurrentBatchOplock function

## Description

A file system or filter driver calls **FsRtlCurrentBatchOplock** to determine whether there are any batch or filter opportunistic locks (oplocks) on a file.

## Parameters

### `Oplock` [in]

Opaque opportunistic lock pointer for the file. This pointer must have been initialized by a previous call to [FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

## Return value

**FsRtlCurrentBatchOplock** returns **TRUE** if there are current outstanding batch or filter opportunistic locks; **FALSE** otherwise.

## Remarks

**FsRtlCurrentBatchOplock** returns **FALSE** if no batch or filter opportunistic locks are currently held.

For detailed information about opportunistic locks, see the Microsoft Windows SDK documentation.

Minifilters should call [FltCurrentBatchOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentbatchoplock) instead of **FsRtlCurrentBatchOplock**.

## See also

[FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[FSCTL_OPLOCK_BREAK_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[FltCurrentBatchOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentbatchoplock)

[FsRtlCheckOplock](https://learn.microsoft.com/windows/win32/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)

[FsRtlOplockFsctrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[FsRtlOplockIsFastIoPossible](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockisfastiopossible)

[FsRtlUninitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializeoplock)