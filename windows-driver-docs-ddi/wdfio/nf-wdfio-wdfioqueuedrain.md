# WdfIoQueueDrain function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueDrain** method causes the framework to stop queuing I/O requests to an I/O queue, while allowing already-queued requests to be delivered and processed.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `DrainComplete` [in, optional]

A pointer to a driver-supplied [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be **NULL**.

### `Context` [in, optional]

An untyped pointer to driver-supplied context information that the framework passes to the [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be **NULL**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

After a driver calls **WdfIoQueueDrain**, the framework stops adding I/O requests to the specified queue. If the framework receives additional requests for the queue, it completes them with a completion status value of STATUS_INVALID_DEVICE_STATE.

If the driver supplies an [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, the framework calls it after all requests that were delivered to the driver have been completed or canceled. You can modify the IRQL at which the callback runs by specifying **ExecutionLevel** in [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) at queue creation time. For more info, see the Remarks section of[*EVT_WDF_IO_QUEUE_STATE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state).

The driver should not call another method that changes queue state, such as [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge) or [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart), before the framework has called [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state).

If a driver specifies **NULL** for *DrainComplete*, the driver can call another state changing operation before requests are completed.

As a best practice, you should only call **WdfIoQueueDrain** when you are certain that the queue's pending I/O requests will complete in a timely fashion. Otherwise, use [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge). For more information, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

After a driver has drained an I/O queue, it can restart the queue by calling [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart).

#### Examples

The following code example drains an I/O queue and calls a driver's **EvtIoQueueDrainComplete** function when all requests that were delivered to the driver have been completed or canceled.

```cpp
WdfIoQueueDrain(
                Queue,
                EvtIoQueueDrainComplete,
                (WDFCONTEXT) myQueueContext
                );
```

## See also

[EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state)

[WdfIoQueueDrainSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrainsynchronously)

[WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge)