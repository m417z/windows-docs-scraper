# WdfIoQueuePurge function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueuePurge** method causes the framework to stop queuing I/O requests to an I/O queue and to cancel unprocessed requests.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `PurgeComplete` [in, optional]

A pointer to a driver-supplied [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be **NULL**.

### `Context` [in, optional]

An untyped pointer to driver-supplied context information that the framework passes to the [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be **NULL**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After a driver calls **WdfIoQueuePurge**, the framework stops adding I/O requests to the specified queue. The framework [cancels](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests) all requests that it has not delivered to the target device and calls the driver's [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function for each. The framework also attempts to cancel (by calling [IoCancelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocancelirp)) any requests delivered to the target device that were not marked [WDF_REQUEST_SEND_OPTION_IGNORE_TARGET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_send_options).

If the framework receives additional requests for the queue, it completes them with a completion status value of STATUS_INVALID_DEVICE_STATE.

If the driver supplies an [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, the framework calls it after all requests that were delivered to the driver have been completed or canceled. You can modify the IRQL at which the callback runs by specifying **ExecutionLevel** in [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) at queue creation time. For more info, see the Remarks section of[*EVT_WDF_IO_QUEUE_STATE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state).

After a driver has purged an I/O queue, it can restart the queue by calling [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart).

If the driver calls [WdfRequestRequeue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestrequeue) after calling **WdfIoQueuePurge**, the requeue attempt may succeed before the purge is complete. In versions 1.9 and earlier of KMDF, this
sequence causes the operating system to crash. This problem is fixed in KMDF version 1.11 and later.

For more information about the **WdfIoQueuePurge** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example purges an I/O queue and does not call a callback function when all requests that were delivered to the driver have been completed or canceled.

```cpp
WdfIoQueuePurge(
                ReadQueue,
                WDF_NO_EVENT_CALLBACK,
                WDF_NO_CONTEXT
                );
```

## See also

[EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state)

[WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain)

[WdfIoQueuePurgeSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurgesynchronously)