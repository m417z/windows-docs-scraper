# FsRtlInitializeOplock function

## Description

**FsRtlInitializeOplock** initializes an opportunistic lock (oplock) pointer.

## Parameters

### `Oplock` [in, out]

Caller-supplied pointer variable that receives the initialized opportunistic lock pointer. This variable must be initialized to **NULL** before the initial call to **FsRtlInitializeOplock**.

## Remarks

File systems and filter drivers call **FsRtlInitializeOplock** to initialize an opaque opportunistic lock pointer.

When the opportunistic lock pointer is no longer needed, it can be uninitialized by calling [FsRtlUninitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializeoplock). The uninitialized opportunistic lock pointer can then be initialized for reuse by calling **FsRtlInitializeOplock**.

For detailed information about opportunistic locks, see the Microsoft Windows SDK documentation.

Minifilters should call [FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock) instead of **FsRtlInitializeOplock**.

## See also

[FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[FSCTL_OPLOCK_BREAK_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock)

[FsRtlCheckOplock](https://learn.microsoft.com/windows/win32/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[FsRtlCurrentBatchOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcurrentbatchoplock)

[FsRtlOplockFsctrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrl)

[FsRtlOplockIsFastIoPossible](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockisfastiopossible)

[FsRtlUninitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializeoplock)