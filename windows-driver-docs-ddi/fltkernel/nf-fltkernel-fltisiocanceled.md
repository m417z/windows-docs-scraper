# FltIsIoCanceled function

## Description

The **FltIsIoCanceled** routine checks if an IRP-based operation has been canceled.

## Parameters

### `CallbackData` [in]

Pointer to the callback data structure for the operation ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)).

## Return value

**FltIsIoCanceled** returns **TRUE** if an IRP-based operation has been canceled and **FALSE** if the operation has not been canceled or if it is not an IRP-based operation.

## Remarks

It is a programming error to call **FltIsIoCanceled** for an operation that is not IRP-based. To determine whether the operation is IRP-based, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCancelFileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelfileopen)

[FltCancelIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio)

[FltClearCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcancelcompletion)

[FltSetCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcancelcompletion)