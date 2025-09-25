# FltUninitializeOplock function

## Description

**FltUninitializeOplock** uninitializes an opportunistic lock (oplock) pointer.

## Parameters

### `Oplock` [in]

Opaque oplock pointer. This pointer must have been initialized by a previous call to [FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock).

## Return value

None

## Remarks

Minifilter drivers call **FltUninitializeOplock** to uninitialize an initialized opportunistic lock (oplock) pointer. The uninitialized oplock pointer can be initialized for reuse by calling [FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock).

For detailed information about opportunistic locks, see the Microsoft Windows SDK documentation.

## See also

[FSCTL_OPBATCH_ACK_CLOSE_PENDING](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-opbatch-ack-close-pending)

[FSCTL_OPLOCK_BREAK_ACKNOWLEDGE](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-acknowledge)

[FSCTL_OPLOCK_BREAK_ACK_NO_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-ack-no-2)

[FSCTL_OPLOCK_BREAK_NOTIFY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-oplock-break-notify)

[FSCTL_REQUEST_BATCH_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-batch-oplock)

[FSCTL_REQUEST_FILTER_OPLOCK](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-filter-oplock)

[FSCTL_REQUEST_OPLOCK_LEVEL_1](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-1)

[FSCTL_REQUEST_OPLOCK_LEVEL_2](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-request-oplock-level-2)

[FltCheckOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckoplock)

[FltCurrentBatchOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentbatchoplock)

[FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock)

[FltOplockFsctrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl)

[FltOplockIsFastIoPossible](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockisfastiopossible)

[FsRtlUninitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializeoplock)