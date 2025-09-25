# WdfUsbTargetPipeFormatRequestForUrb function

## Description

[Applies to KMDF only]

The **WdfUsbTargetPipeFormatRequestForUrb** method builds an USB request for a specified USB pipe, using request parameters that a specified [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) describes, but it does not send the request.

## Parameters

### `PIPE`

A handle to a framework pipe object that was obtained by calling [**WdfUsbInterfaceGetConfiguredPipe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `UrbMemory` [in]

A handle to a framework memory object that contains a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure.

If the driver previously called [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters) to create *UsbDevice*, the driver must use [WdfUsbTargetDeviceCreateUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateurb) or [WdfUsbTargetDeviceCreateIsochUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateisochurb) to create the URB contained in this memory object.

### `UrbMemoryOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address of the URB within the memory that *UrbMemory* specifies. If this pointer is **NULL**, the URB is located at the beginning of the *UrbMemory* memory.

## Return value

**WdfUsbTargetPipeFormatRequestForUrb** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INTEGER_OVERFLOW** | The offset that the *UsbMemoryOffset* parameter specified was invalid. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use **WdfUsbTargetPipeFormatRequestForUrb**, followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), to send a USB request either synchronously or asynchronously. Alternatively, use the [WdfUsbTargetPipeSendUrbSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipesendurbsynchronously) method to send a request synchronously.

The framework does not examine the USB request. If the request changes the state of the USB pipe, the framework will not be aware of the change.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request.

To forward an I/O request that your driver received in an I/O queue, specify the received request's handle for the **WdfUsbTargetPipeFormatRequestForUrb** method's *Request* parameter.

To create a new I/O request, call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate a request object. Supply the request handle for the **WdfUsbTargetPipeFormatRequestForUrb** method's *Request* parameter. You can reuse the request object by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse), so your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.

After calling **WdfUsbTargetPipeFormatRequestForUrb** to format an I/O request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfUsbTargetPipeFormatRequestForUrb** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfUsbTargetPipeFormatRequestForUrb**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfUsbTargetPipeFormatRequestForUrb** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetPipeFormatRequestForUrb** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example creates a memory object that represents a URB. Then, the example initializes the URB, formats a USB request that contains the URB, registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, and sends the request.

```cpp
URB  urb;
PURB  pUrb = NULL;
WDFMEMORY  urbMemory
NTSTATUS status;

status = WdfMemoryCreate(
                         WDF_NO_OBJECT_ATTRIBUTES,
                         NonPagedPool,
                         0,
                         sizeof(struct _URB_GET_CURRENT_FRAME_NUMBER),
                         &urbMemory,
                         NULL
                         );
if (!NT_SUCCESS(status)){
    return status;
}

pUrb = WdfMemoryGetBuffer(
                          urbMemory,
                          NULL
                          );

pUrb->UrbHeader.Length = (USHORT) sizeof(struct _URB_GET_CURRENT_FRAME_NUMBER);
pUrb->UrbHeader.Function = URB_FUNCTION_GET_CURRENT_FRAME_NUMBER;
pUrb->UrbGetCurrentFrameNumber.FrameNumber = 0;

status = WdfUsbTargetPipeFormatRequestForUrb(
                                             pipe,
                                             Request,
                                             urbMemory,
                                             NULL
                                             );
if (!NT_SUCCESS(status)) {
    goto Exit;
}
WdfRequestSetCompletionRoutine(
                               Request,
                               UrbCompletionRoutine,
                               pipe
                               );
if (WdfRequestSend(
                   Request,
                   WdfUsbTargetPipeGetIoTarget(pipe),
                   WDF_NO_SEND_OPTIONS
                   ) == FALSE) {
    status = WdfRequestGetStatus(Request);
    goto Exit;
}
Exit:
if (!NT_SUCCESS(status)) {
    WdfRequestCompleteWithInformation(
                                      Request,
                                      status,
                                      0
                                      );
}
return;
```

## See also

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfRequestSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsetcompletionroutine)

[WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe)