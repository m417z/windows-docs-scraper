# WdfIoQueuePurgeSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueuePurgeSynchronously** method causes the framework to stop queuing I/O requests to an I/O queue and to cancel unprocessed requests and driver-owned cancellable requests.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After a driver calls **WdfIoQueuePurgeSynchronously**, the framework stops adding I/O requests to the specified queue. The framework cancels all requests that it has not delivered to the driver. If the framework receives additional requests for the queue, it completes them with a completion status value of STATUS_INVALID_DEVICE_STATE.

**WdfIoQueuePurgeSynchronously** returns after all the unprocessed and driver-owned requests are completed or canceled.

After a driver has purged an I/O queue, it can restart the queue by calling [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart).

Do not call **WdfIoQueuePurgeSynchronously** from the following queue object event callback functions, regardless of the queue with which the event callback function is associated:

[EvtIoDefault](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_default)
[EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control)
[EvtIoInternalDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_internal_device_control)
[EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read)
[EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write)
For more information about the **WdfIoQueuePurgeSynchronously** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example purges a specified I/O queue.

```cpp
WdfIoQueuePurgeSynchronously(ReadQueue);
```

## See also

[WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge)