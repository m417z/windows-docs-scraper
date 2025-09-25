# WdfRequestForwardToParentDeviceIoQueue function

## Description

[Applies to KMDF only]

The **WdfRequestForwardToParentDeviceIoQueue** method requeues an I/O request from a child device's I/O queue to a specified I/O queue of the child's parent device.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `ParentDeviceQueue` [in]

A handle to a framework queue object.

### `ForwardOptions` [in]

A pointer to a caller-allocated [WDF_REQUEST_FORWARD_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_forward_options) structure.

## Return value

**WdfRequestForwardToParentDeviceIoQueue** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the supplied WDF_REQUEST_FORWARD_OPTIONS structure is invalid. |
| **STATUS_INVALID_PARAMETER** | A member of the supplied WDF_REQUEST_FORWARD_OPTIONS structure contains an invalid value. |
| **STATUS_INVALID_DEVICE_REQUEST** | This value is returned if one of the following occurs:<br><br>* The driver did not obtain the I/O request from an I/O queue.<br>* The source and destination I/O queues are the same.<br>* The specified I/O queue does not belong to the parent device.<br>* The driver has enabled [guaranteed forward progress](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations) and the specified I/O request is reserved for low-memory situations.<br>* The driver did not call [WdfPdoInitAllowForwardingRequestToParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallowforwardingrequesttoparent). |
| **STATUS_WDF_BUSY** | The specified I/O queue is not accepting new requests. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before a driver can call **WdfRequestForwardToParentDeviceIoQueue**, it must call [WdfPdoInitAllowForwardingRequestToParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallowforwardingrequesttoparent).

The driver must use the same [method to access data buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers) (buffered, direct, or neither) for both the parent device and the child device.

If your driver will call **WdfRequestForwardToParentDeviceIoQueue** to requeue an I/O request, the driver must not use the request object as the parent of other framework objects, such as timer objects or work item objects.

If your driver has called [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes) to specify [context space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space) for the *parent* device's request objects, the framework does not add this context space to request objects that the driver receives in a child device's queue. The driver can call [WdfObjectAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectallocatecontext) to add the context space to a request object before the driver calls **WdfRequestForwardToParentDeviceIoQueue**. On the other hand, if the driver called **WdfDeviceInitSetRequestAttributes** for the *child* device's request objects, and if the parent device's request objects use context space that is equal to or smaller than the child device's context space, the driver can use the request object's context space without calling **WdfObjectAllocateContext**.

Currently, the driver must use the [send and forget option](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_forward_options_flags) for all requeued I/O requests. Therefore, be aware that by the time that the framework deletes a requeued request object, it might have already removed the child device that originally received the request object. Thus, the driver must not use the [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) function of a requeued request object to access child device resources, because the resources might be removed before the *EvtCleanupCallback* or *EvtDestroyCallback* function runs.

For more information about **WdfRequestForwardToParentDeviceIoQueue**, see [Requeuing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/requeuing-i-o-requests).

#### Examples

The following code example first determines the parent device of a device that received an I/O request, and then it requeues the I/O request to the parent device's default I/O queue.

```cpp
WDFDEVICE device, parentDevice;
WDF_REQUEST_FORWARD_OPTIONS forwardOptions;
NTSTATUS status;

device = WdfIoQueueGetDevice(WdfRequestGetIoQueue(Request));
parentDevice = WdfPdoGetParent(device);

WDF_REQUEST_FORWARD_OPTIONS_INIT(&forwardOptions);
status = WdfRequestForwardToParentDeviceIoQueue(
             Request,
             WdfDeviceGetDefaultQueue(parentDevice),
             &forwardOptions
             );
if (!NT_SUCCESS(status)) {
    WdfRequestComplete(
                       Request,
                       status
                       );
  }
```

## See also

[WdfPdoInitAllowForwardingRequestToParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallowforwardingrequesttoparent)