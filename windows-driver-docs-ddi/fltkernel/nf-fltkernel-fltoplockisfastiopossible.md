# FltOplockIsFastIoPossible function

## Description

The **FltOplockIsFastIoPossible** routine checks a file's opportunistic lock (oplock) state to determine whether fast I/O can be performed on the file.

## Parameters

### `Oplock` [in]

Opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock).

## Return value

**FltOplockIsFastIoPossible** returns **FALSE** if there are outstanding oplocks on the file that prevent fast I/O from being performed; **TRUE** otherwise.

## Remarks

**FltOplockIsFastIoPossible** determines whether fast I/O can be performed on a file, according to the following conditions:

* If the *Oplock* parameter is **NULL**, or if the value of **Oplock* is **NULL**, there are no outstanding oplocks on the file, and fast I/O can be performed on the file.
* If an exclusive oplock was granted for the file, but no oplock break is in progress, fast I/O can be performed on the file.

For detailed information about opportunistic locks, see the Windows SDK documentation.

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

[FltUninitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializeoplock)

[FsRtlOplockIsFastIoPossible](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockisfastiopossible)