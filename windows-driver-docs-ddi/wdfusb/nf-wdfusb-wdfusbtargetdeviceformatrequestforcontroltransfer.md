# WdfUsbTargetDeviceFormatRequestForControlTransfer function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceFormatRequestForControlTransfer** method builds a USB control transfer request, but it does not send the request.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `SetupPacket` [in]

A pointer to a caller-allocated [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure that describes the control transfer.

### `TransferMemory` [in, optional]

A handle to a framework memory object that describes either an input or an output buffer, depending on the device-specific command. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

### `TransferOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the buffer that *TransferMemory* specifies. If this pointer is **NULL**, the framework uses the entire buffer.

## Return value

**WdfUsbTargetDeviceFormatRequestForControlTransfer** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | An invalid memory descriptor was specified, or the specified I/O request was already queued to an I/O target. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use **WdfUsbTargetDeviceFormatRequestForControlTransfer**, followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend), to send a USB control transfer request either synchronously or asynchronously. Alternatively, use the [WdfUsbTargetDeviceSendControlTransferSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicesendcontroltransfersynchronously) method to send a request synchronously.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and, depending on the type of control transfer, possibly some buffer space.

To forward an I/O request that your driver received in an I/O queue:

1. Specify the received request's handle for the **WdfUsbTargetDeviceFormatRequestForControlTransfer** method's *Request* parameter.
2. Use the received request's input or output buffer for the *TransferMemory* parameter.

   The driver must call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents the request's input or output buffer, and use that handle as the value for *TransferMemory*.

To create a new I/O request and a new buffer:

1. Create a new request object and supply its handle for the **WdfUsbTargetDeviceFormatRequestForControlTransfer** method's *Request* parameter.

   Call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate one or more request objects. You can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.
2. Provide buffer space, and supply the buffer's handle for the **WdfUsbTargetDeviceFormatRequestForControlTransfer** method's *TransferMemory* parameter.

   Your driver must specify this buffer space as a WDFMEMORY handle to framework-managed memory. Your driver can do either of the following:

   * Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to create a new memory buffer, if you want the driver to pass a new buffer to the I/O target.
   * Call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to the memory object that represents a received I/O request's buffer, if you want the driver to pass that buffer's contents to the I/O target.Note that if your driver calls [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) and passes the memory handle to **WdfUsbTargetDeviceFormatRequestForControlTransfer**, the driver must not complete the received I/O request until after the driver deletes, reuses, or reformats the new, driver-created request object. (**WdfUsbTargetDeviceFormatRequestForControlTransfer** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)

After calling **WdfUsbTargetDeviceFormatRequestForControlTransfer** to format an I/O request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfUsbTargetDeviceFormatRequestForControlTransfer** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfUsbTargetDeviceFormatRequestForControlTransfer**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfUsbTargetDeviceFormatRequestForControlTransfer** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

The framework sets the USBD_SHORT_TRANSFER_OK flag in its internal [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb). Setting this flag allows the last packet of a data transfer to be less than the maximum packet size.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetDeviceFormatRequestForControlTransfer** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example creates a request object and a memory object, and then it initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure for a "get status" control transfer. Next, the example calls **WdfUsbTargetDeviceFormatRequestForControlTransfer** to format the request. Then, the example sets a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function and sends the request to an I/O target.

```cpp
WDF_USB_CONTROL_SETUP_PACKET packet;
NTSTATUS status;
WDF_OBJECT_ATTRIBUTES attributes;
WDFMEMORY memHandle;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);

status = WdfRequestCreate(
                          &attributes,
                          WdfUsbTargetDeviceGetIoTarget(
                              UsbTargetDevice,
                              &request
                              )
                          );
if (!NT_SUCCESS(status)){
    return status;
}

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = request;
status = WdfMemoryCreate(
                         &attributes,
                         NonPagedPool,
                         0,
                         sizeof(USHORT),
                         &memHandle,
                         NULL
                         );
if (!NT_SUCCESS(status)){
    return status;
}

WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS(
                                             &packet,
                                             BmRequestToDevice,
                                             0
                                             );
status = WdfUsbTargetDeviceFormatRequestForControlTransfer(
                         UsbTargetDevice,
                         request,
                         &packet,
                         memHandle,
                         NULL
                         );
if (!NT_SUCCESS(status)){
    return status;
}
WdfRequestSetCompletionRoutine(
                               request,
                               MyCompletionRoutine,
                               NULL
                               );
if (WdfRequestSend(
                   request,
                   WdfUsbTargetDeviceGetIoTarget(UsbTargetDevice),
                   NULL
                   ) == FALSE) {
    status = WdfRequestGetStatus(request);
}
```

## See also

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_get_status)

[WdfUsbTargetDeviceSendControlTransferSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicesendcontroltransfersynchronously)