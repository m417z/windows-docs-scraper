# WdfIoQueueAssignForwardProgressPolicy function

## Description

[Applies to KMDF only]

The **WdfIoQueueAssignForwardProgressPolicy** method enables the framework's ability to [guarantee forward progress](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations) for a specified I/O queue.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `ForwardProgressPolicy` [in]

A pointer to a driver-allocated [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.

## Return value

**WdfIoQueueAssignForwardProgressPolicy** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of these values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY structure is incorrect. |
| **STATUS_INSUFFICIENT_RESOURCES** | The amount of available memory is too low. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values). In addition, if your driver's [EvtIoAllocateResourcesForReservedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_resources_for_reserved_request) callback function returns an error status value, **WdfIoQueueAssignForwardProgressPolicy** returns that value.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The**WdfIoQueueAssignForwardProgressPolicy** method creates request objects that the framework reserves for low-memory situations and registers callback functions that the framework calls to handle low-memory situations.

In KMDF version 1.9, the I/O queue that the *Queue* parameter represents must be a device's default I/O queue, or a queue for which your driver has called [WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching). The driver can call **WdfIoQueueAssignForwardProgressPolicy** any time after it has called **WdfDeviceConfigureRequestDispatching**.

In KMDF versions 1.11 and later, the I/O queue that the *Queue* parameter represents can be any queue that receives a request directly from the framework. For example, the driver might specify a queue to which it will [dynamically forward IRPs](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-irps-to-i-o-queues).

Before **WdfIoQueueAssignForwardProgressPolicy** returns, the framework does the following:

* Creates and stores the number of request objects that the driver has specified for the **TotalForwardProgressRequests** member of the [WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy) structure.
* If the driver previously called [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes), each allocation includes context space that **WdfDeviceInitSetRequestAttributes** specified.
* Calls the driver's [EvtIoAllocateResourcesForReservedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_resources_for_reserved_request) callback function for each request object that the framework creates.

After the driver has called **WdfIoQueueAssignForwardProgressPolicy** to create reserved request objects, the framework uses those reserved objects whenever its attempt to create a new request object fails. (Typically, such failures are caused by low memory situations.)

The framework deletes its reserved request objects only when it deletes the framework queue object that they belong to. If your driver calls [WdfDeviceInitSetRequestAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetrequestattributes) and specifies an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function for its request objects, the framework calls these callback functions for its reserved request objects when it deletes the objects.

For more information about the **WdfIoQueueAssignForwardProgressPolicy** method and how to use the framework's guaranteed forward progress capability, see [Guaranteeing Forward Progress of I/O Operations](https://learn.microsoft.com/windows-hardware/drivers/wdf/guaranteeing-forward-progress-of-i-o-operations).

#### Examples

This code example configures a previously created I/O queue to receive write requests, and then it enables guaranteed forward progress for the queue.

```cpp
#define MAX_RESERVED_REQUESTS 10

WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY queueForwardProgressPolicy;
WDFQUEUE writeQueue;
NTSTATUS status = STATUS_SUCCESS;
...
status = WdfDeviceConfigureRequestDispatching(
             device,
             writeQueue,
             WdfRequestTypeWrite
             );
if(!NT_SUCCESS(status)) {
    return status;
}
WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_DEFAULT_INIT(
    &queueForwardProgressPolicy,
    MAX_RESERVED_REQUESTS
    );
status = WdfIoQueueAssignForwardProgressPolicy(
             writeQueue,
             &queueForwardProgressPolicy
             );
if(!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[EvtIoAllocateResourcesForReservedRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_allocate_resources_for_reserved_request)

[WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ns-wdfio-_wdf_io_queue_forward_progress_policy)

[WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching)