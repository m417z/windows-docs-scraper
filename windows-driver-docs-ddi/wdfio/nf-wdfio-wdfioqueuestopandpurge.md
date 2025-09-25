# WdfIoQueueStopAndPurge function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueStopAndPurge** method prevents an I/O queue from delivering new requests and cancels existing unprocessed requests and driver-owned cancellable requests, but the queue receives and stores new requests.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `StopAndPurgeComplete` [in, optional]

A pointer to a driver-supplied [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be NULL.

### `Context` [in, optional]

An untyped pointer to driver-supplied context information that the framework passes to the [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be NULL.

## Remarks

The **WdfIoQueueStopAndPurge** method prevents an I/O queue from delivering I/O requests to the driver while allowing new requests to be added to the queue.

In addition, it cancels unprocessed requests in the queue and driver-owned cancellable requests (requests that were delivered to the driver that driver has not completed or requeued). If new requests are added while **WdfIoQueueStopAndPurge** is in progress, these new requests are not delivered until driver calls [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart).

In contrast, the [WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop) method does not cancel unprocessed requests in the queue or driver-owned cancellable requests.

If this method causes the framework to cancel an unprocessed request in a queue, the framework calls the driver's [EvtIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_canceled_on_queue) callback function for that queue, if the driver has supplied one.

If the driver supplies an [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, the framework calls it after all requests that were delivered to the driver have been completed or canceled.

The **WdfIoQueueStopAndPurge** method enables the queue to receive new requests, even if the queue was not receiving new requests before the driver called **WdfIoQueueStopAndPurge**. For example, a driver might call [WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain), which causes the framework to stop adding new I/O requests to the queue. The driver's subsequent call of **WdfIoQueueStopAndPurge** causes the framework to resume adding requests to the queue.

In contrast, [WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge) causes the framework to stop adding I/O requests to the specified queue.

A bug check occurs if the driver supplies an invalid object handle.

#### Examples

The following code example stops and purges a specified I/O queue. After all requests that were delivered to the driver have been completed or canceled, the framework calls a driver's EvtIoQueueStateStopAndPurge function.

```cpp
WDFCONTEXT stopandpurgeContext;

stopandpurgeContext = &myContext;

WdfIoQueueStopAndPurge(
               queue,
               EvtIoQueueStateStopAndPurge,
               stopandpurgeContext
               );
```

## See also

[EvtIoCanceledOnQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_canceled_on_queue)

[EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state)

[WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart)

[WdfIoQueueStopAndPurgeSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopandpurgesynchronously)