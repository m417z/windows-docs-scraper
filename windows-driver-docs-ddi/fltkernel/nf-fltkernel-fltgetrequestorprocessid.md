# FltGetRequestorProcessId function

## Description

The **FltGetRequestorProcessId** routine returns the unique 32-bit process ID for the process associated with the thread that requested a given I/O operation.

## Parameters

### `CallbackData` [in]

Pointer to the callback data structure ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) for the I/O operation.

## Return value

**FltGetRequestorProcessId** returns the process ID for the process associated with the thread that originally requested the I/O operation. If the operation is not associated with any thread, **FltGetRequestorProcessId** returns zero.

## Remarks

**FltGetRequestorProcessId** returns the process ID for the process that the requesting thread is currently attached to. This process may or may not be the same process that created the thread.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltGetRequestorProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetrequestorprocess)