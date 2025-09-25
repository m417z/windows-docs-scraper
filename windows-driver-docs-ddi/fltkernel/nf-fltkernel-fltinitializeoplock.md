# FltInitializeOplock function

## Description

The **FltInitializeOplock** routine initializes an opportunistic lock (oplock) pointer.

## Parameters

### `Oplock` [out]

Caller-supplied pointer variable that receives the initialized opaque oplock pointer. This variable must be initialized to **NULL** before the initial call to **FltInitializeOplock**.

## Return value

None

## Remarks

When the oplock pointer is no longer needed, it can be uninitialized by calling [FltUninitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializeoplock). The uninitialized oplock pointer can then be initialized for reuse by calling **FltInitializeOplock**.

To request an oplock or respond to an oplock break notification, call [FltOplockFsctrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl).

For detailed information about opportunistic locks, see the Microsoft Windows SDK documentation.

## See also

[FltCheckOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckoplock)

[FltCurrentBatchOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentbatchoplock)

[FltOplockFsctrl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockfsctrl)

[FltOplockIsFastIoPossible](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltoplockisfastiopossible)

[FltUninitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializeoplock)

[FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)