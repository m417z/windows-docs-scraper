# FltClearCancelCompletion function

## Description

**FltClearCancelCompletion** clears a cancel routine that was specified for an I/O operation.

## Parameters

### `CallbackData` [in]

Pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation.

## Return value

If no cancel routine was previously set or if IRP cancellation is already in progress, **FltClearCancelCompletion** returns STATUS_CANCELLED. Otherwise, it returns STATUS_SUCCESS.

## Remarks

A minifilter driver calls **FltClearCancelCompletion** to clear a cancel routine that was specified for an I/O operation by a previous call to [FltSetCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcancelcompletion). The operation must be an IRP-based I/O operation. To determine whether a given callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

To cancel an I/O operation, call [FltCancelIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCancelIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio)

[FltSetCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcancelcompletion)