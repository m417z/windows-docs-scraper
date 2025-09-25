# WdfRequestSetCompletionRoutine function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestSetCompletionRoutine** method registers or deregisters a completion routine for the specified framework request object.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `CompletionRoutine` [in, optional]

A pointer to a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, if the driver is registering a completion routine, or **NULL** of the driver is deregistering a previously registered completion routine.

### `CompletionContext` [in, optional]

An untyped pointer to driver-defined context information that the framework passes to the [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function. This parameter is optional and can be **NULL**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If your driver forwards I/O requests, but if you want your driver to be notified when a lower-level driver completes the request, your driver can provide a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function and call **WdfRequestSetCompletionRoutine** to register the function. The framework calls the callback function after a lower-level driver completes the I/O request.

If the driver sets an I/O completion callback, the driver must format the request before sending it to the default I/O target even if the driver does not change any of the parameters in the request. Formatting can be done using [WdfRequestFormatRequestUsingCurrentType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestformatrequestusingcurrenttype).

For more information about **WdfRequestSetCompletionRoutine**, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

For a code example that uses **WdfRequestSetCompletionRoutine**, see [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)