# FltGetRequestorProcessIdEx function

## Description

The **FltGetRequestorProcessIdEx** routine returns the kernel-mode handle for the process that is associated with the thread that requested a given I/O operation.

## Parameters

### `CallbackData` [in]

A pointer to an [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that identifies the thread and the I/O operation.

## Return value

The **FltGetRequestorProcessIdEx** routine returns the kernel-mode handle for the process that is associated with the thread that originally requested the I/O operation. If the operation is not associated with any thread, FltGetRequestorProcessIdEx returns **NULL**.

## Remarks

The **FltGetRequestorProcessIdEx** routine returns the kernel-mode handle for the process that the requesting thread is currently attached to. This process may or may not be the same process that created the thread.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltGetRequestorProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetrequestorprocess)