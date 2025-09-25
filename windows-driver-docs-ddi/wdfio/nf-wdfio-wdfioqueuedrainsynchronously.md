# WdfIoQueueDrainSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueDrainSynchronously** method causes the framework to stop queuing I/O requests to an I/O queue, while allowing already-queued requests to be delivered and processed. The method returns after all requests are completed or canceled.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After a driver calls **WdfIoQueueDrainSynchronously**, the framework stops adding I/O requests to the specified queue. If the framework receives additional requests for the queue, it completes them with a completion status value of STATUS_INVALID_DEVICE_STATE.

The driver should not call another method that changes queue state, such as [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge) or [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart), before the call to **WdfIoQueueDrainSynchronously** has returned.

As a best practice, you should only call **WdfIoQueueDrainSynchronously** when you are certain that the queue's pending I/O requests will complete in a timely fashion. Otherwise, use [WdfIoQueuePurgeSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurgesynchronously). For more information, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

After a driver has drained an I/O queue, it can restart the queue by calling [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart).

Do not call **WdfIoQueueDrainSynchronously** from the following queue object event callback functions, regardless of the queue with which the event callback function is associated:

[EvtIoDefault](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_default)
[EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control)
[EvtIoInternalDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_internal_device_control)
[EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read)
[EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write)

#### Examples

The following code example drains an I/O queue.

```cpp
WdfIoQueueDrainSynchronously(queue);
```

## See also

[WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain)