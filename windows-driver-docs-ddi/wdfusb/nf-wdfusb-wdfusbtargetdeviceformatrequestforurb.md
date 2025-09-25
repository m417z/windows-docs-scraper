# WdfUsbTargetDeviceFormatRequestForUrb function

## Description

[Applies to KMDF only]

The **WdfUsbTargetDeviceFormatRequestForUrb** method builds a USB request for a specified USB device, using request parameters that are described by a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb), but it does not send the request.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `UrbMemory` [in]

A handle to a framework memory object that contains a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) structure or one of the structure's union members. (All of the URB structure's union members contain the [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure.)

If the driver previously called [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters) to create *UsbDevice*, the driver must use [WdfUsbTargetDeviceCreateUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateurb) or [WdfUsbTargetDeviceCreateIsochUrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreateisochurb) to create the URB contained in this memory object. Otherwise, a bug check occurs.

### `UrbMemoryOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address of the URB within the memory that *UrbMemory* specifies. If this pointer is **NULL**, the URB is located at the beginning of the *UrbMemory* memory.

## Return value

**WdfUsbTargetDeviceFormatRequestForUrb** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |
| **STATUS_INTEGER_OVERFLOW** | The offset that the *UsbMemoryOffset* parameter specified was invalid. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use **WdfUsbTargetDeviceFormatRequestForUrb**, followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), to send a USB control transfer request either synchronously or asynchronously. Alternatively, use the [WdfUsbTargetDeviceSendUrbSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicesendurbsynchronously) method to send a request synchronously.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request.

To forward an I/O request that your driver received in an I/O queue, specify the received request's handle for the **WdfUsbTargetDeviceFormatRequestForUrb** method's *Request* parameter.

To create a new I/O request, call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate a request object. Supply the request handle for the **WdfUsbTargetDeviceFormatRequestForUrb** method's *Request* parameter. You can reuse the request object by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.

After calling **WdfUsbTargetDeviceFormatRequestForUrb** to format an I/O request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target. Do not use the [send and forget option](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_forward_options_flags) to send the request.

Multiple calls to **WdfUsbTargetDeviceFormatRequestForUrb** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfUsbTargetDeviceFormatRequestForUrb**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfUsbTargetDeviceFormatRequestForUrb** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetDeviceFormatRequestForUrb** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example creates a memory object to hold a URB structure, initializes the URB structure, and calls **WdfUsbTargetDeviceFormatRequestForUrb** to format a request that uses the URB structure's contents. Then, the example registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function and sends the request to an I/O target.

```cpp
WDFMEMORY urbMemory;
URB *urbBuffer;

status = WdfMemoryCreate(
                         WDF_NO_OBJECT_ATTRIBUTES,
                         NonPagedPool,
                         0,
                         sizeof(struct _URB_CONTROL_GET_CONFIGURATION_REQUEST),
                         &urbMemory,
                         NULL
                         );

if (!NT_SUCCESS(status)){
    return status;
}
urbBuffer = (PURB) WdfMemoryGetBuffer(
                                      urbMemory,
                                      NULL
                                      );
urbBuffer->UrbHeader.Function =  URB_FUNCTION_GET_CONFIGURATION;
urbBuffer->UrbHeader.Length = sizeof(struct _URB_CONTROL_GET_CONFIGURATION_REQUEST);
urbBuffer->UrbControlGetConfigurationRequest.TransferBufferLength = 1 ;
urbBuffer->UrbControlGetConfigurationRequest.TransferBufferMDL = NULL;
urbBuffer->UrbControlGetConfigurationRequest.TransferBuffer = outBuffer;
urbBuffer->UrbControlGetConfigurationRequest.UrbLink = NULL;

status = WdfUsbTargetDeviceFormatRequestForUrb(
                                               deviceContext->WdfUsbTargetDevice,
                                               request,
                                               urbMemory,
                                               NULL
                                               );
WdfRequestSetCompletionRoutine(
                              request,
                              MyCompletionRoutine,
                              NULL);

if (WdfRequestSend(
                   request,
                   WdfUsbTargetDeviceGetIoTarget(UsbDevice),
                   NULL
                   ) == FALSE) {
    status = WdfRequestGetStatus(request);
}
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)

[WdfUsbTargetDeviceSendUrbSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicesendurbsynchronously)