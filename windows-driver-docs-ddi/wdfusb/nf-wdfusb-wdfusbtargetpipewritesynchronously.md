# WdfUsbTargetPipeWriteSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfUsbTargetPipeWriteSynchronously** method builds a write request and sends it synchronously to a specified USB output pipe.

## Parameters

### `Pipe` [in]

A handle to a framework pipe object that was obtained by calling [WdfUsbInterfaceGetConfiguredPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbinterfacegetconfiguredpipe).

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information, see the following Remarks section.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the request. This pointer is optional and can be **NULL**. For more information, see the following Remarks section.

### `MemoryDescriptor` [in, optional]

A pointer to a caller-allocated [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that describes the buffer that contains data that will be written to the device. For more information about this buffer, see the following Remarks section.

### `BytesWritten` [out, optional]

A pointer to a location that receives the number of bytes written, if the operation succeeds. This parameter is optional and can be **NULL**.

## Return value

**WdfUsbTargetPipeWriteSynchronously** returns the I/O target's completion status value if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that the *RequestOptions* parameter points to was incorrect. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | Insufficient memory was available. |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller's IRQL was not PASSIVE_LEVEL, an invalid memory descriptor was specified, the pipe's type was not valid, the transfer direction was invalid, or the specified I/O request was already queued to an I/O target. |
| **STATUS_IO_TIMEOUT** | The driver supplied a time-out value and the request did not complete within the allotted time. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfUsbTargetPipeWriteSynchronously** method to send write requests synchronously. To send write requests asynchronously, use [WdfUsbTargetPipeFormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipeformatrequestforwrite), followed by [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

The specified pipe must be an output pipe, and the pipe's [type](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-get_type) must be **WdfUsbPipeTypeBulk** or **WdfUsbPipeTypeInterrupt**.

The **WdfUsbTargetPipeWriteSynchronously** method does not return until the request has completed, unless the driver supplies a time-out value in the *RequestOptions* parameter's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, or unless an error is detected.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward an I/O request that your driver received in an I/O queue:

1. Specify the received request's handle for the *Request* parameter.
2. Use the received request's input buffer for the *MemoryDescriptor* parameter.

   The driver must call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) to obtain a handle to a framework memory object that represents the request's input buffer and then place that handle in the [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that *MemoryDescriptor* points to.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Supply a **NULL** request handle for the **WdfUsbTargetPipeWriteSynchronously** method's *Request* parameter, or create a new request object and supply its handle:
   * If you supply a **NULL** request handle, the framework uses an internal request object. This technique is simple to use, but the driver cannot cancel the request.
   * If you call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to create one or more request objects, you can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). This technique enables your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function to preallocate request objects for a device. Additionally, another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to cancel the request, if necessary.

   Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.
2. Provide buffer space for the **WdfUsbTargetPipeWriteSynchronously** method's *MemoryDescriptor* parameter.

   Your driver can specify this buffer space as a locally allocated buffer, as a WDFMEMORY handle, or as a MDL. You can use whichever method is most convenient.

   If necessary, the framework converts the buffer description to one that is correct for the I/O target's [method for accessing data buffers](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

   The following techniques are available:

   * Supply a local buffer

     Because **WdfUsbTargetPipeWriteSynchronously** handles I/O requests synchronously, the driver can create request buffers that are local to the calling routine, as the following code example shows.

     ```cpp
     WDF_MEMORY_DESCRIPTOR  memoryDescriptor;
     MY_BUFFER_TYPE  myBuffer;
     WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&memoryDescriptor,
                                       (PVOID) &myBuffer,
                                       sizeof(myBuffer));
     ```
   * Supply a WDFMEMORY handle

     Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to obtain a handle to framework-managed memory, as the following code example shows.

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
     Alternatively, the driver can call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) to obtain a handle to a framework memory object that represents a received I/O request's input buffer, if you want the driver to pass that buffer's contents to the I/O target. The driver must not complete the received I/O request until the new request that **WdfUsbTargetPipeWriteSynchronously** sends to the I/O target has been deleted, reused, or reformatted. (**WdfUsbTargetPipeWriteSynchronously** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)
   * Supply a MDL

     Drivers can obtain the MDL that is associated with a received I/O request by calling [WdfRequestRetrieveInputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputwdmmdl).

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about the **WdfUsbTargetPipeWriteSynchronously** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example creates a memory object, obtains a pointer to the object's buffer, fills the buffer, and uses the buffer as input to **WdfUsbTargetPipeWriteSynchronously**.

```cpp
WDF_MEMORY_DESCRIPTOR  writeBufDesc;
WDFMEMORY  wdfMemory;
ULONG  writeSize, bytesWritten;
size_t  bufferSize;
NTSTATUS status;

writeSize = SMALL_BUF_LEN;
status = WdfMemoryCreate(
                         WDF_NO_OBJECT_ATTRIBUTES,
                         NonPagedPool,
                         0,
                         writeSize,
                         &wdfMemory,
                         NULL
                         );
if (!NT_SUCCESS(status)){
    return status;
}

writeBuffer = WdfMemoryGetBuffer(
                                 wdfMemory,
                                 &bufferSize
                                 );

FillMyBuffer(
             writeBuffer,
             writeSize
             );

WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(
                                  &writeBufDesc,
                                  writeBuffer,
                                  writeSize
                                  );

status = WdfUsbTargetPipeWriteSynchronously(
                                            pipeHandle,
                                            NULL,
                                            NULL,
                                            &writeBufDesc,
                                            &bytesWritten
                                            );
```

## See also

[WDF_MEMORY_DESCRIPTOR_INIT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_buffer)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryGetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorygetbuffer)

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfUsbTargetPipeReadSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetpipereadsynchronously)