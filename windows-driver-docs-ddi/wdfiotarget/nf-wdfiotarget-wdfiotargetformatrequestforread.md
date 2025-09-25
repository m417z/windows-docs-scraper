# WdfIoTargetFormatRequestForRead function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetFormatRequestForRead** method builds a read request for an I/O target but does not send the request.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a specialized I/O target supplies.

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `OutputBuffer` [in, optional]

A handle to a framework memory object. This object represents a buffer that will receive data from the I/O target. This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

### `OutputBufferOffset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. The framework uses these values to determine the beginning address and length, within the output buffer, for the data transfer. If this pointer is **NULL**, the data transfer begins at the beginning of the output buffer, and the transfer size is the buffer size.

### `DeviceOffset` [in, optional]

A pointer to a variable that specifies a starting offset for the transfer. The I/O target (that is, the next-lower driver) defines how to use this value. For example, the drivers in a disk's driver stack might specify an offset from the beginning of the disk. The I/O target obtains this information in the **Parameters.Read.DeviceOffset** member of the request's [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure. This pointer is optional. Most drivers set this pointer to **NULL**.

## Return value

**WdfIoTargetFormatRequestForRead** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_DEVICE_REQUEST** | The transfer length was larger than the buffer length, or the I/O request was already queued to an I/O target. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate system resources (typically memory). |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfIoTargetFormatRequestForRead** method, followed by the [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) method, to send read requests either synchronously or asynchronously. Alternatively, use the [WdfIoTargetSendReadSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendreadsynchronously) method to send read requests synchronously.

You can forward an I/O request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward an I/O request that your driver received in an I/O queue:

1. Specify the received request's handle for the **WdfIoTargetFormatRequestForRead** method's *Request* parameter.
2. Use the received request's output buffer for the **WdfIoTargetFormatRequestForRead** method's *OutputBuffer* parameter.

   The driver must call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to a framework memory object that represents the request's output buffer and must use that handle as the value for *OutputBuffer*.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Create a new request object and supply its handle for the **WdfIoTargetFormatRequestForRead** method's *Request* parameter.

   Call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate one or more request objects. You can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.
2. Provide buffer space, and supply the buffer's handle for the **WdfIoTargetFormatRequestForRead** method's *OutputBuffer* parameter.

   Your driver must specify this buffer space as a WDFMEMORY handle to framework-managed memory. Your driver can do either of the following:

   * Call [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated) to create a new memory buffer, if you want the driver to pass a new buffer to the I/O target.
   * Call [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) to obtain a handle to the memory object that represents a received I/O request's buffer, if you want the driver to pass that buffer's contents to the I/O target.Note that if your driver calls [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) and passes the memory handle to **WdfIoTargetFormatRequestForRead**, the driver must not complete the received I/O request until after the driver deletes, reuses, or reformats the new, driver-created request object. (**WdfIoTargetFormatRequestForRead** increments the memory object's reference count. Deleting, reusing, or reformatting a request object decrements the memory object's reference count.)

Some I/O targets accept read requests that have a zero-length buffer. For such I/O targets, your driver can specify **NULL** for the *OutputBuffer* parameter.

After a driver calls **WdfIoTargetFormatRequestForRead** to format an I/O request, it must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfIoTargetFormatRequestForRead** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfIoTargetFormatRequestForRead**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. All subsequent calls to **WdfIoTargetFormatRequestForRead** for the reused request object will return STATUS_SUCCESS, if parameter values do not change. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.)

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about **WdfIoTargetFormatRequestForRead**, see [Sending I/O Requests to General I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/sending-i-o-requests-to-general-i-o-targets).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example creates a framework memory object for a read request's output buffer, formats the read request, registers a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, and sends the read request to an I/O target.

```cpp
WDFREQUEST  request;
NTSTATUS  status;
WDFMEMORY  memory;
WDF_OBJECT_ATTRIBUTES  attributes;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
status = WdfMemoryCreate(
                         &attributes,
                         NonPagedPool,
                         DRIVER_TAG,
                         READ_BUF_SIZE,
                         &memory,
                         NULL
                         );

if (!NT_SUCCESS(status)) {
    return status;
}

status = WdfIoTargetFormatRequestForRead(
                                         IoTarget,
                                         request,
                                         memory,
                                         NULL,
                                         NULL
                                         );
if (!NT_SUCCESS(status)) {
        return status;
}
WdfRequestSetCompletionRoutine(
                               request,
                               MyReadRequestCompletionRoutine,
                               targetInfo
                               );
if (WdfRequestSend(
                   request,
                   IoTarget,
                   WDF_NO_SEND_OPTIONS
                   ) == FALSE) {
        status = WdfRequestGetStatus(request);
}
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset)

[WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetFormatRequestForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforwrite)

[WdfIoTargetSendReadSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendreadsynchronously)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)