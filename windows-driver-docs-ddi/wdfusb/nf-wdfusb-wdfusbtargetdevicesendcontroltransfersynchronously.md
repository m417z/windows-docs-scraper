# WdfUsbTargetDeviceSendControlTransferSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetDeviceSendControlTransferSynchronously** method builds a USB control transfer request and sends it synchronously to an I/O target.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the request. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

### `SetupPacket` [in]

A pointer to a caller-allocated [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure that describes the control transfer.

### `MemoryDescriptor` [in, optional]

A pointer to a caller-allocated [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that describes either an input or an output buffer, depending on the device-specific command. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

### `BytesTransferred` [out, optional]

A pointer to a location that receives the number of bytes that are transferred. This parameter is optional and can be **NULL**.

## Return value

**WdfUsbTargetDeviceSendControlTransferSynchronously** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | An invalid memory descriptor was specified, or the specified I/O request was already queued to an I/O target. |
| **STATUS_IO_TIMEOUT** | The driver supplied a time-out value and the request did not complete within the allotted time. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfUsbTargetDeviceSendControlTransferSynchronously** method to send a USB control transfer request synchronously. To send such requests asynchronously, use [WdfUsbTargetDeviceFormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforcontroltransfer), followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

The **WdfUsbTargetDeviceSendControlTransferSynchronously** method does not return until the request has completed, unless the driver supplies a time-out value in the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that the *RequestOptions* parameter points to, or unless an error is detected.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and, depending on the type of control transfer, possibly some buffer space.

To forward an I/O request that your driver received in an I/O queue:

1. Specify the received request's handle for the *Request* parameter.
2. Use the received request's input or output buffer for the *MemoryDescriptor* parameter.

   The driver can call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents the request's input or output buffer and then place that handle in the [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that the driver supplies for the *MemoryDescriptor* parameter.

To create and send a new request:

1. Supply a **NULL** request handle in the *Request* parameter, or create a new request object and supply its handle:
   * If you supply a **NULL** request handle, the framework uses an internal request object. This technique is simple to use, but the driver cannot cancel the request.
   * If you call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to create one or more request objects, you can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). This technique enables your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function to preallocate request objects for a device. Additionally, another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to cancel the request, if necessary.

   Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.
2. Provide buffer space for the **WdfUsbTargetDeviceSendControlTransferSynchronously** method's *MemoryDescriptor* parameter.

   Your driver can specify this buffer space as a locally allocated buffer, as a WDFMEMORY handle, or as an MDL. You can use whichever method is most convenient.

   If necessary, the framework converts the buffer description to one that is correct for the I/O target's [method for accessing data buffers](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

   The following techniques are available:

   * Supply a local buffer

     Because **WdfUsbTargetDeviceSendControlTransferSynchronously** handles I/O requests synchronously, the driver can create request buffers that are local to the calling routine, as shown in the following code example.

     ```cpp
     WDF_MEMORY_DESCRIPTOR  memoryDescriptor;
     MY_BUFFER_TYPE  myBuffer;
     WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&memoryDescriptor,
                                       (PVOID) &myBuffer,
                                       sizeof(myBuffer));
     ```
   * Supply a WDFMEMORY handle

     Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to obtain a handle to framework-managed memory, as shown in the following code example.

     ```cpp
     WDF_MEMORY_DESCRIPTOR  memoryDescriptor;
     WDFMEMORY  memoryHandle = NULL;
     status = WdfMemoryCreate(NULL,
                              NonPagedPool,
                              POOL_TAG,
                              MY_BUFFER_SIZE,
                              &memoryHandle,
                              NULL);
     WDF_MEMORY_DESCRIPTOR_INIT_HANDLE(&memoryDescriptor,
                                       memoryHandle,
                                       NULL);
     ```
     Alternatively, the driver can call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents a received I/O request's buffer, if you want the driver to pass that buffer's contents to the I/O target. The driver must not complete the received I/O request until the new request that **WdfUsbTargetDeviceSendControlTransferSynchronously** sends to the I/O target has been deleted, reused, or reformatted. (**WdfUsbTargetDeviceSendControlTransferSynchronously** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)
   * Supply an MDL

     Drivers can obtain MDLs that are associated with a received I/O request by calling [WdfRequestRetrieveInputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputwdmmdl) or [WdfRequestRetrieveOutputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputwdmmdl).

The framework sets the USBD_SHORT_TRANSFER_OK flag in its internal [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb). Setting this flag allows the last packet of a data transfer to be less than the maximum packet size.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetDeviceSendControlTransferSynchronously** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure and then calls **WdfUsbTargetDeviceSendControlTransferSynchronously** to send a vendor-specific control transfer.

```cpp
WDF_USB_CONTROL_SETUP_PACKET  controlSetupPacket;

WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR(
                                         &controlSetupPacket,
                                         BmRequestHostToDevice,
                                         BmRequestToDevice,
                                         USBFX2LK_REENUMERATE,
                                         0,
                                         0
                                         );

status = WdfUsbTargetDeviceSendControlTransferSynchronously(
                                         UsbDevice,
                                         WDF_NO_HANDLE,
                                         NULL,
                                         &controlSetupPacket,
                                         NULL,
                                         NULL
                                         );
return status;
```

## See also

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfUsbTargetDeviceFormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforcontroltransfer)

[WdfUsbTargetDeviceSendUrbSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicesendurbsynchronously)