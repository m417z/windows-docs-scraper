# KsReleaseIrpOnCancelableQueue function

## Description

The **KsReleaseIrpOnCancelableQueue** function releases an acquired IRP that is already on a queue that can be canceled. The function sets the cancel function and completes the canceling of the IRP, if necessary. The function can be called at IRQ level DISPATCH_LEVEL or lower.

## Parameters

### `Irp` [in]

Specifies the IRP to release.

### `DriverCancel` [in, optional]

Optional parameter that specifies the cancel routine to use. If this is **NULL**, the standard **KsCancelRoutine** is used.

## Return value

None