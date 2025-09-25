# WdfIoTargetFormatRequestForInternalIoctl function

## Description

[Applies to KMDF only]

The **WdfIoTargetFormatRequestForInternalIoctl** method builds an internal device control request for an I/O target but does not send the request.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a specialized I/O target supplies.

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `IoctlCode` [in]

An I/O control code (IOCTL) that the I/O target supports.

### `InputBuffer` [in, optional]

A handle to a framework memory object. This object represents a buffer that contains data that will be sent to the I/O target. For more information, see the following Remarks section.

### `InputBufferOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the input buffer, for the data transfer. If this pointer is **NULL**, the data transfer begins at the beginning of the input buffer, and the transfer size is the buffer size.

### `OutputBuffer` [in, optional]

A handle to a framework memory object. This object represents a buffer that will receive data from the I/O target. For more information, see the following Remarks section.

### `OutputBufferOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the output buffer, for the data transfer. If this pointer is **NULL**, the data transfer begins at the beginning of the output buffer, and the transfer size is the buffer size.

## Return value

**WdfIoTargetFormatRequestForInternalIoctl** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_DEVICE_REQUEST** | The transfer length was larger than the buffer length, or the I/O request was already queued to an I/O target. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate system resources (typically memory). |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfIoTargetFormatRequestForInternalIoctl** method, followed by the [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) method, to send internal device control requests either synchronously or asynchronously. Alternatively, use the [WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously) method to send internal device control requests synchronously.

For more information about internal device control requests, see [Using I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-i-o-control-codes).

You can forward an internal device control request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward an internal device control request that your driver received in an I/O queue:

1. Specify the received request's handle for the **WdfIoTargetFormatRequestForInternalIoctl** method's *Request* parameter.
2. Use the received request's input buffer for the **WdfIoTargetFormatRequestForInternalIoctl** method's *InputBuffer* parameter.

   The driver must call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) to obtain a handle to the request's input buffer, and it must use that handle as the value for *InputBuffer*.
3. Use the received request's output buffer for the **WdfIoTargetFormatRequestForInternalIoctl** method's *OutputBuffer* parameter.

   The driver must call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to the request's output buffer, and it must use that handle as the value for *OutputBuffer*.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Create a new request object and supply its handle for the **WdfIoTargetFormatRequestForInternalIoctl** method's *Request* parameter.

   Call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate one or more request objects. You can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.
2. Provide buffer space, and supply the buffer's handle for the **WdfIoTargetFormatRequestForInternalIoctl** method's *InputBuffer* and *OutputBuffer* parameters.

   Your driver must specify this buffer space as WDFMEMORY handles to framework-managed memory. Your driver can do either of the following:

   * Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to create a new memory buffer, if you want the driver to pass a new buffer to the I/O target.
   * Call [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to the memory object that represents a received I/O request's buffer, if you want the driver to pass that buffer's contents to the I/O target.Note that if your driver calls [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) or [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) and passes the memory handle to **WdfIoTargetFormatRequestForInternalIoctl**, the driver must not complete the received I/O request until after the driver deletes, reuses, or reformats the new, driver-created request object. (**WdfIoTargetFormatRequestForInternalIoctl** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)

After a driver calls **WdfIoTargetFormatRequestForInternalIoctl** to format a device control request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfIoTargetFormatRequestForInternalIoctl** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfIoTargetFormatRequestForInternalIoctl**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfIoTargetFormatRequestForInternalIoctl** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (However, if the driver does not call the same request-formatting method each time, additional resources might be allocated. Additionally, if the [I/O control code](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-i-o-control-codes) specifies a transfer type of METHOD_BUFFERED, the framework must allocate a system buffer for each request, and that allocation could fail because of insufficient memory resources.)

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about **WdfIoTargetFormatRequestForInternalIoctl**, see [Sending I/O Requests to General I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/sending-i-o-requests-to-general-i-o-targets).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example creates a framework memory object that is a child of a request object. Next, the example obtains the buffer that the memory object contains and initializes the buffer. Then, the example formats the request, sets a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, and sends the request to an I/O target.

```cpp
WDF_OBJECT_ATTRIBUTES memoryObjAttr;
WDFMEMORY memory;
NTSTATUS status;
IOCTL_DATA *pIoctlData;

WDF_OBJECT_ATTRIBUTES_INIT(&memoryObjAttr);
memoryObjAttr.ParentObject = Request;

status = WdfMemoryCreate(
                         &memoryObjAttr,
                         NonPagedPool,
                         0,
                         sizeof(IOCTL_DATA),
                         &memory,
                         NULL
                         );
if (!NT_SUCCESS(status)) {
    goto Done;
}
pIoctlData = WdfMemoryGetBuffer(
                                memory,
                                NULL
                                );
RtlZeroMemory(
              pIoctlData,
              sizeof(IOCTL_DATA)
              );
pIoctlData->Member1 = MY_DATA;

status = WdfIoTargetFormatRequestForInternalIoctl(
                                                  IoTarget,
                                                  Request,
                                                  IOCTL_INTERNAL_GET_MY_DATA,
                                                  memory,
                                                  NULL,
                                                  WDF_NO_HANDLE,
                                                  NULL
                                                  );

if (!NT_SUCCESS(status)) {
    goto Done;
}

WdfRequestSetCompletionRoutine(
                               Request,
                               MyRequestCompletion,
                               NULL
                               );

if (WdfRequestSend(
                   Request,
                   IoTarget,
                   NULL
                   ) == FALSE) {
    status = WdfRequestGetStatus(Request);
}
else {
    status = STATUS_SUCCESS;
}
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetFormatRequestForIoctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforioctl)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory)

[WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)