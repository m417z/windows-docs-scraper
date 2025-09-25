# FltCancelIo function

## Description

The **FltCancelIo** routine cancels an I/O operation.

## Parameters

### `CallbackData` [in]

Pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation.

## Return value

**FltCancelIo** returns **TRUE** if the I/O operation was canceled successfully. Otherwise, it returns **FALSE**.

## Remarks

A minifilter driver that initiates an I/O operation by calling a routine such as [FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio) can cancel the operation by calling **FltCancelIo**. The operation must be an IRP-based I/O operation, it must not be currently posted to the minifilter driver's own work queue, and it must not have been completed.

If the IRP has a cancel routine, **FltCancelIo** sets the IRP's cancel bit and calls the cancel routine.

If the IRP does not have a cancel routine, and therefore the IRP is not cancelable, **FltCancelIo** sets the IRP's cancel bit and returns **FALSE**. The IRP should be canceled at a later time when it becomes cancelable.

If a minifilter driver that did not initiate the IRP-based I/O operation calls **FltCancelIo**, the results are unpredictable. For example, the IRP might be completed with a success NTSTATUS code even though its cancel bit was set.

**FltCancelIo** returns **FALSE** if any of the following conditions are true:

* The operation is not an IRP-based I/O operation.
* No cancel routine is specified for the I/O operation.
* The I/O operation has already been canceled.

To determine whether a given callback data structure represents an IRP-based I/O operation, use the FLT_IS_IRP_OPERATION macro.

To specify a cancel routine for an I/O operation, call [FltSetCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcancelcompletion).

To clear a cancel routine that was set for an I/O operation, call [FltClearCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcancelcompletion).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltClearCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcancelcompletion)

[FltPerformAsynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio)

[FltReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

[FltSetCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcancelcompletion)

[FltWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltwritefile)