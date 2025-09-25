# FltGetRequestorProcess function

## Description

The **FltGetRequestorProcess** routine returns a process pointer for the thread that requested a given I/O operation.

## Parameters

### `CallbackData` [in]

Pointer to the callback data structure ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) for the I/O operation.

## Return value

**FltGetRequestorProcess** returns a process pointer for the thread that requested the I/O operation. If the operation is not associated with any thread, **FltGetRequestorProcess** returns **NULL**.

## Remarks

**FltGetRequestorProcess** returns a pointer to the process that the requesting thread is currently attached to. This process may or may not be the same process that created the thread.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltGetRequestorProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetrequestorprocessid)