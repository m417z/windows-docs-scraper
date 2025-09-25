# WdfRequestWdmFormatUsingStackLocation function

## Description

[Applies to KMDF only]

The **WdfRequestWdmFormatUsingStackLocation** method formats an I/O request by copying the contents of a specified WDM [I/O stack location](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations) structure to the next stack location in the request.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Stack` [in]

A pointer to an [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure that contains driver-supplied information.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfRequestWdmFormatUsingStackLocation** method copies the information that is supplied by the *Stack* parameter into the next IRP stack location in the request.

**WdfRequestWdmFormatUsingStackLocation** formats the request independent of whether the I/O target object of the request is local or remote.

If you want to set a completion routine for the request, your driver must call [WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine) after calling **WdfRequestWdmFormatUsingStackLocation**.

For more information about **WdfRequestWdmFormatUsingStackLocation**, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

#### Examples

The following code example supplies an [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure for an I/O request, sets a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, and then sends the request to an I/O target.

```cpp
IO_STACK_LOCATION  ioStackLocation;
BOOLEAN sendStatus;
...
//
// Initialize the IO_STACK_LOCATION structure here.
//
...
//
// Assign the IO_STACK_LOCATION structure to the request.
//
WdfRequestWdmFormatUsingStackLocation(
                                      request,
                                      &ioStackLocation
                                      );
//
// Assign a CompletionRoutine callback function.
//
WdfRequestSetCompletionRoutine(
                               Request,
                               RequestTimeoutComplete,
                               NULL
                               );
//
// Send the request.
//
sendStatus = WdfRequestSend(
                            Request,
                            target,
                            NULL
                            );
```

The following code example illustrates how to send a PnP [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) IRP to an IO target.

```cpp
target = WdfDeviceGetIoTarget(Device);
status = WdfRequestCreate(WDF_NO_OBJECT_ATTRIBUTES,
                          target,
                          &request);

if (!NT_SUCCESS(status)) {
    // Log failure and leave
}

//
// PnP IRPs must be initialized with STATUS_NOT_SUPPORTED
//
WDF_REQUEST_REUSE_PARAMS_INIT(&reuse,
                              WDF_REQUEST_REUSE_NO_FLAGS,
                              STATUS_NOT_SUPPORTED);

WdfRequestReuse(request, &reuse);

//
// Initialize device capabilities
//
RtlZeroMemory(Capabilities, sizeof(DEVICE_CAPABILITIES));
Capabilities->Size = sizeof(DEVICE_CAPABILITIES);
Capabilities->Version  =  1;
Capabilities->Address  = (ULONG) -1;
Capabilities->UINumber = (ULONG) -1;
RtlZeroMemory(&stack, sizeof(stack));
stack.MajorFunction = IRP_MJ_PNP;
stack.MinorFunction = IRP_MN_QUERY_CAPABILITIES;
stack.Parameters.DeviceCapabilities.Capabilities = Capabilities;

WdfRequestWdmFormatUsingStackLocation(request, &stack);

WDF_REQUEST_SEND_OPTIONS_INIT(&options,
                              WDF_REQUEST_SEND_OPTION_SYNCHRONOUS);

if (WdfRequestSend(request, target, &options) == FALSE) {
    // Log failure
}

status = WdfRequestGetStatus(request);

if (!NT_SUCCESS(status)) {
    // Log failure
}

// Remember to delete the WDFREQUEST after creating it
if (request != NULL) {
    WdfObjectDelete(request);
}
```

## See also

[WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine)