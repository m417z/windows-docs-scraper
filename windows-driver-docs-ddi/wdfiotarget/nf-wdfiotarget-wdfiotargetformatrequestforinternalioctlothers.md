# WdfIoTargetFormatRequestForInternalIoctlOthers function

## Description

[Applies to KMDF only]

The **WdfIoTargetFormatRequestForInternalIoctlOthers** method builds a non-standard internal device control request for an I/O target but does not send the request.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate), or from a method that a specialized I/O target supplies.

### `Request` [in]

A handle to a framework request object. For more information, see the following Remarks section.

### `IoctlCode` [in]

An I/O control code (IOCTL) that the I/O target supports.

### `OtherArg1` [in, optional]

A handle to a framework memory object. This object represents a buffer that the driver uses for request-specific, driver-defined context information. For more information, see the following Remarks section. This parameter is optional and can be **NULL**.

### `OtherArg1Offset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. Drivers can use these values to specify the beginning address and length of a segment of the context area that is specified by *OtherArg1*. This parameter is optional and can be **NULL**.

### `OtherArg2` [in, optional]

A handle to a framework memory object. This object represents a buffer that the driver uses for request-specific, driver-defined context information. For more information, see the following Remarks section. This parameter is optional and can be **NULL**.

### `OtherArg2Offset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. Drivers can use these values to specify the beginning address and length of a segment of the context area that is specified by *OtherArg2*. This parameter is optional and can be **NULL**.

### `OtherArg4` [in, optional]

A handle to a framework memory object. This object represents a buffer that the driver uses for request-specific, driver-defined context information. For more information, see the following Remarks section. This parameter is optional and can be **NULL**.

### `OtherArg4Offset` [in, optional]

A pointer to a caller-allocated [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/ns-wdfmemory-_wdfmemory_offset) structure that supplies optional byte offset and length values. Drivers can use these values to specify the beginning address and length of a segment of the context area that is specified by *OtherArg4*. This parameter is optional and can be **NULL**.

## Return value

**WdfIoTargetFormatRequestForInternalIoctlOthers** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INVALID_DEVICE_REQUEST** | The transfer length was larger than the buffer length, or the I/O request was already queued to an I/O target. |
| **STATUS_INSUFFICIENT_RESOURCES** | The framework could not allocate system resources (typically memory). |
| **STATUS_REQUEST_NOT_ACCEPTED** | The I/O request packet ([IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)) that the *Request* parameter represents does not provide enough [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structures to allow the driver to forward the request. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Use the **WdfIoTargetFormatRequestForInternalIoctlOthers** method, followed by the [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) method, to send non-standard internal device control requests either synchronously or asynchronously. Alternatively, use the [WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously) method to send non-standard internal device control requests synchronously.

You can forward a non-standard internal device control request that your driver received in an I/O queue, or you can create and send a new request. In either case, the framework requires a request object and some buffer space.

To forward a non-standard internal device control request that your driver received in an I/O queue:

1. Specify the received request's handle for the **WdfIoTargetFormatRequestForInternalIoctlOthers** method's *Request* parameter.
2. Use the received request's context information for the **WdfIoTargetFormatRequestForInternalIoctlOthers** method's *OtherArg1*, *OtherArg2*, an *OtherArg4* parameters.

   To obtain these parameter values, the driver must call [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters) and use the **DeviceIoControl** member of the [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) structure that is returned.

For more information about forwarding an I/O request, see [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

Drivers often divide received I/O requests into smaller requests that they send to an I/O target, so your driver might create new requests.

To create a new I/O request:

1. Create a new request object and supply its handle for the **WdfIoTargetFormatRequestForInternalIoctlOthers** method's *Request* parameter.

   Call [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) to preallocate one or more request objects. You can reuse these request objects by calling [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse). Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can preallocate request objects for a device.
2. Provide context buffers, if the request requires them, and supply buffer handles for the **WdfIoTargetFormatRequestForInternalIoctlOthers** method's *OtherArg1*, *OtherArg2*, and *OtherArg4* parameters.

   Your driver must specify this buffer space as WDFMEMORY handles to framework-managed memory. To obtain WDFMEMORY handles, the driver calls [WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate) or [WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated).

After a driver calls **WdfIoTargetFormatRequestForInternalIoctlOthers** to format a device control request, the driver must call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend) to send the request (either synchronously or asynchronously) to an I/O target.

Multiple calls to **WdfIoTargetFormatRequestForInternalIoctlOthers** that use the same request do not cause additional resource allocations. Therefore, to reduce the chance that [WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate) will return STATUS_INSUFFICIENT_RESOURCES, your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function can call **WdfRequestCreate** to preallocate one or more request objects for a device. The driver can subsequently reuse (call [WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)), reformat (call **WdfIoTargetFormatRequestForInternalIoctlOthers**), and resend (call [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)) each request object without risking a STATUS_INSUFFICIENT_RESOURCES return value from a later call to **WdfRequestCreate**. (If the driver does not call the same request-formatting method each time, additional resources might be allocated.) All subsequent calls to **WdfIoTargetFormatRequestForInternalIoctlOthers** for the reused request object will return STATUS_SUCCESS, if parameter values do not change.

For information about obtaining status information after an I/O request completes, see [Obtaining Completion Information](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests).

For more information about **WdfIoTargetFormatRequestForInternalIoctlOthers**, see [Sending I/O Requests to General I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/sending-i-o-requests-to-general-i-o-targets).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example creates a framework memory object, obtains the buffer that the memory object contains, and initializes the buffer. Then, the example formats the request, sets a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, and sends the request to an I/O target.

```cpp
PIRB pIrb;
WDFMEMORY memory;
NTSTATUS status;

status = WdfMemoryCreate(
                         WDF_NO_OBJECT_ATTRIBUTES,
                         NonPagedPool,
                         0,
                         sizeof(IRB),
                         &memory,
                         NULL
                         );
if (!NT_SUCCESS(status)) {
    goto Done;
}
pIrb = WdfMemoryGetBuffer(
                          memory,
                          NULL
                          );

pIrb->FunctionNumber = REQUEST_ALLOCATE_ADDRESS_RANGE;
pIrb->Flags = 0;
pIrb->u.AllocateAddressRange.Mdl = pAsyncAddressData->pMdl;
pIrb->u.AllocateAddressRange.fulFlags = fulFlags;
pIrb->u.AllocateAddressRange.nLength = nLength;
pIrb->u.AllocateAddressRange.MaxSegmentSize = MaxSegmentSize;
pIrb->u.AllocateAddressRange.fulAccessType = fulAccessType;
pIrb->u.AllocateAddressRange.fulNotificationOptions = fulNotificationOptions;
pIrb->u.AllocateAddressRange.Callback = NULL;
pIrb->u.AllocateAddressRange.Context = NULL;
pIrb->u.AllocateAddressRange.Required1394Offset = *Required1394Offset;
pIrb->u.AllocateAddressRange.FifoSListHead = NULL;
pIrb->u.AllocateAddressRange.FifoSpinLock = NULL;
pIrb->u.AllocateAddressRange.AddressesReturned = 0;
pIrb->u.AllocateAddressRange.p1394AddressRange = pAsyncAddressData->AddressRange;
pIrb->u.AllocateAddressRange.DeviceExtension = deviceExtension;

status = WdfIoTargetFormatRequestForInternalIoctlOthers(
                                                        IoTarget,
                                                        Request,
                                                        IOCTL_1394_CLASS,
                                                        memory,
                                                        NULL,
                                                        NULL,
                                                        NULL,
                                                        NULL,
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

[WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfRequestCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcreate)

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)

[WdfRequestReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestreuse)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)