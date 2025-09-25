# WdfRequestComplete function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestComplete** method completes a specified I/O request and supplies a completion status.

## Parameters

### `Request` [in]

A handle to the framework request object that represents the I/O request that is being completed.

### `Status` [in]

An [NTSTATUS value](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) that represents the completion status of the request. Valid status values include, but are not limited to, the following:

#### STATUS_SUCCESS

The driver is successfully completing the request.

#### STATUS_CANCELLED

The driver is canceling the request.

#### STATUS_UNSUCCESSFUL

The driver has encountered an error while processing the request.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After a driver calls **WdfRequestComplete**, higher-level drivers on the driver stack can call [WdfRequestGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetstatus) to obtain the completion status value that was specified for the *Status* parameter. Typically, drivers call **WdfRequestGetStatus** from within a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function.

After a call to **WdfRequestComplete** returns, the request handle is no longer valid unless the driver has called [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) to add one or more additional reference counts to the request object. Note that after **WdfRequestComplete** returns, the driver must not attempt to access the associated WDM IRP structure, even if it has called **WdfObjectReference**. This requirement extends to accessing the associated WDM IRP structure by calling methods on the WDFREQUEST, like **WdfRequestRetrieveOutputBuffer** or **WdfRequestRetrieveInputBuffer**.

After a driver calls **WdfRequestComplete**, the framework calls the driver's [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the request, if the driver has supplied one.

Instead of calling **WdfRequestComplete**, the driver can call [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation) or [WdfRequestCompleteWithPriorityBoost](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithpriorityboost). See the Remarks of [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation) for more information.

When your driver calls **WdfRequestComplete**, the framework supplies a default value that the system uses to boost the run-time priority of the thread that requested the I/O operation. For information about default priority boost values, see [Specifying Priority Boosts When Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-priority-boosts-when-completing-i-o-requests). Your driver can call [WdfRequestCompleteWithPriorityBoost](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithpriorityboost) to override the default priority boost value.

For more information about calling **WdfRequestComplete**, see [Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

#### Examples

The following code example is a section of a request handler. The request handler accepts only read and write requests, and it completes each request with an error status if the request type is not read or write.

```cpp
VOID
MyEvtIoDefault(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request
    )
{
    WDF_REQUEST_PARAMETERS  params;
    WDF_DMA_DIRECTION  direction;

...
    WDF_REQUEST_PARAMETERS_INIT(&params);

    WdfRequestGetParameters(
                            Request,
                            &params
                            );

    //
    // Validate and gather parameters.
    //
    switch (params.Type) {
        case WdfRequestTypeRead:
            length = params.Parameters.Read.Length;
            direction = WdfDmaDirectionReadFromDevice;
            break;
        case WdfRequestTypeWrite:
            length = params.Parameters.Write.Length;
            direction = WdfDmaDirectionWriteToDevice;
            break;
        default:
            WdfRequestComplete(
                               Request,
                               STATUS_INVALID_DEVICE_REQUEST
                               );
            return;
    }
...
}
```

## See also

[WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters)

[WDF_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_parameters_init)

[WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference)

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)

[WdfRequestCompleteWithPriorityBoost](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithpriorityboost)

[WdfRequestGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetstatus)