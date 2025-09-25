# WdfRequestCompleteWithInformation function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestCompleteWithInformation** method stores completion information and then completes a specified I/O request with a supplied completion status.

## Parameters

### `Request` [in]

A handle to the request object.

### `Status` [in]

An [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) that represents the completion status of the request. Valid status values include, but are not limited to, the following:

#### STATUS_SUCCESS

The driver successfully completed the request.

#### STATUS_CANCELLED

The driver canceled the request.

#### STATUS_UNSUCCESSFUL

The driver encountered an error while processing the request.

### `Information` [in]

A ULONG_PTR that is set to a request-dependent value. For example, on successful completion of a transfer request, this is set to the number of bytes transferred. This field is not extensible by the driver.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

For read, write and IOCTL requests, it is necessary for the driver to call **WdfRequestCompleteWithInformation**

For a non-data transfer request, calling [**WdfRequestComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) instead is an option.

Calling **WdfRequestCompleteWithInformation** is equivalent to calling [WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation) and then calling [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete).

After a call to **WdfRequestCompleteWithInformation** returns, the request handle is no longer valid unless the driver has called [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) to add one or more additional reference counts to the request object. Note that after **WdfRequestCompleteWithInformation** returns, the driver must not attempt to access the associated WDM IRP structure, even if it has called **WdfObjectReference**.

When your driver calls **WdfRequestCompleteWithInformation**, the framework supplies a default value that the system uses to boost the run-time priority of the thread that requested the I/O operation. For information about default priority boost values, see [Specifying Priority Boosts When Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-priority-boosts-when-completing-i-o-requests). Your driver can call [WdfRequestCompleteWithPriorityBoost](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithpriorityboost) to override the default priority boost value.

For more information about calling **WdfRequestCompleteWithInformation**, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For a code example that shows how to use **WdfRequestCompleteWithInformation** to retrieve the number of bytes copied, see the [VirtualSerial2 driver sample](https://github.com/Microsoft/Windows-driver-samples/blob/df271b80bdbb556707d9b4af1b06151ded561884/serial/VirtualSerial2/queue.c#L542).

#### Examples

The following code example shows how a driver for a USB device might call **WdfRequestCompleteWithInformation** in a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function .

```cpp
VOID
EvtRequestReadCompletionRoutine(
    IN WDFREQUEST  Request,
    IN WDFIOTARGET  Target,
    PWDF_REQUEST_COMPLETION_PARAMS  CompletionParams,
    IN WDFCONTEXT  Context
    )
{
    NTSTATUS  status;
    size_t  bytesRead = 0;
    PWDF_USB_REQUEST_COMPLETION_PARAMS  usbCompletionParams;

    UNREFERENCED_PARAMETER(Target);
    UNREFERENCED_PARAMETER(Context);

    status = CompletionParams->IoStatus.Status;
    usbCompletionParams = CompletionParams->Parameters.Usb.Completion;
    bytesRead =  usbCompletionParams->Parameters.PipeRead.Length;

    if (NT_SUCCESS(status)){
        TraceEvents(
                    TRACE_LEVEL_INFORMATION,
                    DBG_READ,
                    "Number of bytes read: %I64d\n",
                    (INT64)bytesRead
                    );
    } else {
        TraceEvents(
                    TRACE_LEVEL_ERROR,
                    DBG_READ,
                    "Read failed - request status 0x%x UsbdStatus 0x%x\n",
                    status,
                    usbCompletionParams->UsbdStatus
                    );
    }
    WdfRequestCompleteWithInformation(
                                      Request,
                                      status,
                                      bytesRead
                                      );
    return;
}
```

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params)

[WDF_USB_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_request_completion_params)

[WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestCompleteWithPriorityBoost](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithpriorityboost)

[WdfRequestSetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetinformation)