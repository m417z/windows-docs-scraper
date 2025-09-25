# WdfIoTargetSendIoctlSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetSendIoctlSynchronously** method builds a device control request and sends it synchronously to an I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a specialized I/O target supplies.

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `IoctlCode` [in]

An I/O control code (IOCTL) that the I/O target supports.

### `InputBuffer` [in, optional]

A pointer to a caller-allocated [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that describes a buffer that will be written to the I/O target. For more information, see the following Remarks section. This parameter is optional and can be **NULL** if the request does not send data.

### `OutputBuffer` [in, optional]

A pointer to a caller-allocated [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that describes a buffer that will receive data from the I/O target. For more information, see the following Remarks section. This parameter is optional and can be **NULL** if the request does not receive data.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the request. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

### `BytesReturned` [out, optional]

A pointer to a location that receives information (such as the number of bytes that were transferred) that another driver supplies when it completes the request by calling [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation). This pointer is optional and can be **NULL**.

## Return value

If the operation succeeds, **WdfIoTargetSendIoctlSynchronously** returns after the device control request completes, and the return value is the request's completion status value. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that the *RequestOptions* parameter pointed to was incorrect. |
| **STATUS_INVALID_DEVICE_REQUEST** | The request was already queued to an I/O target. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework cannot allocate system resources (typically memory). |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfIoTargetSendIoctlSynchronously** method to send device control requests synchronously. To send device control requests asynchronously, use the [WdfIoTargetFormatRequestForIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforioctl) method, followed by the [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) method.

For more information about device control requests, see [Using I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-i-o-control-codes).

The **WdfIoTargetSendIoctlSynchronously** method does not return until the request has completed, unless the driver supplies a time-out value in the *RequestOptions* parameter's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, or unless an error is detected.

You can forward a device control request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward a device control request that your driver received in an I/O queue:

1. Specify the received request's handle for the **WdfIoTargetSendIoctlSynchronously** method's *Request* parameter.
2. Use the received request's input buffer for the **WdfIoTargetSendIoctlSynchronously** method's *InputBuffer* parameter.

   The driver must call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) to obtain a handle to a framework memory object that represents the request's input buffer. Then the driver must place that handle in the [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that the driver supplies for the *InputBuffer* parameter of **WdfIoTargetSendIoctlSynchronously**.
3. Use the received request's output buffer for the **WdfIoTargetSendIoctlSynchronously** method's *OutputBuffer* parameter.

   The driver must call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents the request's output buffer. Then the driver must place that handle in the [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that the driver supplies for the *OutputBuffer* parameter of **WdfIoTargetSendIoctlSynchronously**.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Supply a **NULL** request handle for the **WdfIoTargetSendIoctlSynchronously** method's *Request* parameter, or create a new request object and supply its handle:
   * If you supply a **NULL** request handle, the framework uses an internal request object. This technique is simple to use, but the driver cannot cancel the request.
   * If you call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to create one or more request objects, you can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). This technique enables your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function to preallocate request objects for a device. Additionally, another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to cancel the request, if necessary.

   Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.
2. Provide buffer space for the **WdfIoTargetSendIoctlSynchronously** method's *InputBuffer* and *OutputBuffer* parameters, if the request requires them.

   Your driver can specify this buffer space as locally allocated buffers, as WDFMEMORY handles, or as memory descriptor lists (MDLs). You can use whichever method is most convenient.

   If necessary, the framework converts the buffer descriptions so that they are correct for the IOCTL's transfer type. For more information about IOCTL transfer types, see [Defining I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-i-o-control-codes).

   The following techniques to specify buffer space are available:

   * Supply local buffers.

     Because **WdfIoTargetSendIoctlSynchronously** handles I/O requests synchronously, the driver can create request buffers that are local to the calling routine, as the following code example shows.

     ```cpp
     WDF_MEMORY_DESCRIPTOR  MemoryDescriptor;
     MY_BUFFER_TYPE  MyBuffer;
     WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&MemoryDescriptor,
                                       (PVOID) &MyBuffer,
                                       sizeof(MyBuffer));
     ```
   * Supply WDFMEMORY handles.

     Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to obtain a handle to framework-managed memory, as the following code example shows.

     ```cpp
     WDF_MEMORY_DESCRIPTOR  MemoryDescriptor;
     WDFMEMORY  MemoryHandle = NULL;
     status = WdfMemoryCreate(NULL,
                              NonPagedPool,
                              POOL_TAG,
                              MY_BUFFER_SIZE,
                              &MemoryHandle,
                              NULL);
     WDF_MEMORY_DESCRIPTOR_INIT_HANDLE(&MemoryDescriptor,
                                       MemoryHandle,
                                       NULL);
     ```
     Alternatively, the driver can call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents a received I/O request's buffer, if you want the driver to pass that buffer's contents to the I/O target. The driver must not complete the received I/O request until the new request that **WdfIoTargetSendIoctlSynchronously** sends to the I/O target has been deleted, reused, or reformatted. (**WdfIoTargetSendIoctlSynchronously** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)
   * Supply MDLs.

     Drivers can obtain MDLs that are associated with a received I/O request by calling [WdfRequestRetrieveInputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputwdmmdl) and [WdfRequestRetrieveOutputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputwdmmdl).

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about **WdfIoTargetSendIoctlSynchronously**, see [Sending I/O Requests to General I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/sending-i-o-requests-to-general-i-o-targets).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example defines a local buffer, initializes a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure, and calls **WdfIoTargetSendIoctlSynchronously**. This example specifies **NULL** for the request object handle, so the framework will create a new request object for the I/O target.

```cpp
WDF_MEMORY_DESCRIPTOR  outputDescriptor;
NTSTATUS  status;
HID_COLLECTION_INFORMATION  collectionInformation;

WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(
                                  &outputDescriptor,
                                  (PVOID) &collectionInformation,
                                  sizeof(HID_COLLECTION_INFORMATION)
                                  );

status = WdfIoTargetSendIoctlSynchronously(
                                           hidTarget,
                                           NULL,
                                           IOCTL_HID_GET_COLLECTION_INFORMATION,
                                           NULL,
                                           &outputDescriptor,
                                           NULL,
                                           NULL
                                           );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor)

[WDF_MEMORY_DESCRIPTOR_INIT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_buffer)

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetFormatRequestForIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforioctl)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory)

[WdfRequestRetrieveInputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputwdmmdl)

[WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory)

[WdfRequestRetrieveOutputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputwdmmdl)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)