# WdfIoTargetSendReadSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetSendReadSynchronously** method builds a read request and sends it synchronously to an I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate) or from a method that a specialized I/O target supplies.

### `Request` [in, optional]

A handle to a framework request object. This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

### `OutputBuffer` [in, optional]

A pointer to a caller-allocated [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that describes the buffer that will receive data from the device.This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

### `DeviceOffset` [in, optional]

A pointer to a location that specifies a starting offset for the transfer. The I/O target (that is, the next-lower driver) defines how to use this value. For example, the drivers in a disk's driver stack might specify an offset from the beginning of the disk. The I/O target obtains this information in the **Parameters.Read.DeviceOffset** member of the request's [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure. This pointer is optional. Most drivers set this pointer to **NULL**.

### `RequestOptions` [in, optional]

A pointer to a caller-allocated [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure that specifies options for the read request. This pointer is optional and can be **NULL**.

### `BytesRead` [out, optional]

A pointer to a location that receives the number of bytes read, if the operation succeeds. This pointer is optional and can be **NULL**.

## Return value

If the operation succeeds, **WdfIoTargetSendReadSynchronously** returns after the I/O request completes, and the return value is the request's completion status value. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the WDF_REQUEST_SEND_OPTIONS structure that the *RequestOptions* parameter pointed to was incorrect. |
| **STATUS_INVALID_DEVICE_REQUEST** | The I/O request was already queued to an I/O target. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate system resources (typically memory). |
| **STATUS_IO_TIMEOUT** | The driver supplied a time-out value and the request did not complete within the allotted time. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfIoTargetSendReadSynchronously** method to send read requests synchronously. To send read requests asynchronously, use the [WdfIoTargetFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforread) method, followed by the [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) method.

**WdfIoTargetSendReadSynchronously** does not return until the request has completed, unless the driver supplies a time-out value in the *RequestOptions* parameter's [WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options) structure, or unless an error is detected.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward an I/O request that your driver received in an I/O queue:

1. Specify the received request's handle for the *Request* parameter.
2. Use the received request's output buffer for the **WdfIoTargetSendReadSynchronously** method's *OutputBuffer* parameter.

   The driver must call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents the request's output buffer. Then the driver must place that handle in the [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure that the driver supplies for the *OutputBuffer* parameter.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Supply a **NULL** request handle for the **WdfIoTargetSendReadSynchronously** method's *Request* parameter, or create a new request object and supply its handle:
   * If you supply a **NULL** request handle, the framework uses an internal request object. This technique is simple to use, but the driver cannot cancel the request.
   * If you call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to create one or more request objects, you can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). This technique enables your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function to preallocate request objects for a device. Additionally, another driver thread can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to cancel the request, if necessary.

   Your driver can specify a non-**NULL** *RequestOptions* parameter, whether the driver provides a non-**NULL** or a **NULL** *Request* parameter. You can, for example, use the *RequestOptions* parameter to specify a time-out value.
2. Provide buffer space for the **WdfIoTargetSendReadSynchronously** method's *OutputBuffer* parameter.

   Your driver can specify this buffer space as a locally allocated buffer, as a WDFMEMORY handle, or as a memory descriptor list (MDL). You can use whichever method is most convenient.

   If necessary, the framework converts the buffer description to one that is correct for the I/O target's [method for accessing data buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

   The following techniques to specify buffer space are available:

   * Supply a local buffer.

     Because **WdfIoTargetSendReadSynchronously** handles I/O requests synchronously, the driver can create request buffers that are local to the calling routine, as the following code example shows.

     ```cpp
     WDF_MEMORY_DESCRIPTOR  MemoryDescriptor;
     MY_BUFFER_TYPE  MyBuffer;
     WDF_MEMORY_DESCRIPTOR_INIT_BUFFER(&MemoryDescriptor,
                                       (PVOID) &MyBuffer,
                                       sizeof(MyBuffer));
     ```
   * Supply a WDFMEMORY handle.

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
     Alternatively, the driver can call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents a received I/O request's output buffer, if you want the driver to pass that buffer's contents to the I/O target. The driver must not complete the received I/O request until the new request that **WdfIoTargetSendReadSynchronously** sends to the I/O target has been deleted, reused, or reformatted. (**WdfIoTargetSendReadSynchronously** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)
   * Supply an MDL.

     Drivers can obtain the MDL that is associated with a received I/O request by calling [WdfRequestRetrieveOutputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputwdmmdl).

Some I/O targets accept read requests that have a zero-length buffer. For such I/O targets, your driver can specify **NULL** for the *OutputBuffer* parameter.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about **WdfIoTargetSendReadSynchronously**, see [Sending I/O Requests to General I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/sending-i-o-requests-to-general-i-o-targets).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example creates a framework memory object, initializes a [WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor) structure, and passes the structure to **WdfIoTargetSendReadSynchronously**. This example specifies **NULL** for the request object handle, so the framework will create a new request object for the I/O target.

```cpp
WDF_MEMORY_DESCRIPTOR  MemoryDescriptor;
WDFMEMORY  MemoryHandle = NULL;
ULONG_PTR  bytesRead = NULL;

status = WdfMemoryCreate(
                         NULL,
                         NonPagedPool,
                         POOL_TAG,
                         MY_BUFFER_SIZE,
                         &MemoryHandle,
                         NULL
                         );
WDF_MEMORY_DESCRIPTOR_INIT_HANDLE(
                                  &MemoryDescriptor,
                                  MemoryHandle,
                                  NULL
                                  );
status = WdfIoTargetSendReadSynchronously(
                                          ioTarget,
                                          NULL,
                                          &MemoryDescriptor,
                                          NULL,
                                          NULL,
                                          &bytesRead
                                          );

```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_MEMORY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdf_memory_descriptor)

[WDF_MEMORY_DESCRIPTOR_INIT_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdf_memory_descriptor_init_handle)

[WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters)

[WDF_REQUEST_SEND_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetFormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforread)

[WdfIoTargetSendWriteSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendwritesynchronously)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory)

[WdfRequestRetrieveOutputWdmMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputwdmmdl)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)