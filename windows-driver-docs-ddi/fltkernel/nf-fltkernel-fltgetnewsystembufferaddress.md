# FltGetNewSystemBufferAddress function

## Description

The **FltGetNewSystemBufferAddress** function retrieves the AssociatedIrp.SystemBuffer buffer, which the file system has allocated. A minifilter driver's post-callback routine calls this function.

## Parameters

### `CallbackData` [in]

A pointer to a [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that represents an I/O operation.

## Return value

If the AssociatedIrp.SystemBuffer buffer was allocated by the file system, **FltGetNewSystemBufferAddress** returns a pointer to this buffer; otherwise it returns **NULL**.

## Remarks

A minifilter driver's post-callback routine calls **FltGetNewSystemBufferAddress** function to retrieve a pointer to the AssociatedIrp.SystemBuffer buffer that the file system has allocated. A minifilter driver should call this function only when the FLTFL_CALLBACK_DATA_NEW_SYSTEM_BUFFER flag is set in *CallbackData.Flags*.

When the file system allocates its own AssociatedIrp.SystemBuffer buffer, Filter Manager will set the FLTFL_CALLBACK_DATA_NEW_SYSTEM_BUFFER flag. This signals the minifilter that the buffer they received in the pre-operation is not the one that has the data read from the file system.

If the FLTFL_CALLBACK_DATA_NEW_SYSTEM_BUFFER flag is not set, then this routine returns **NULL**.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)