# WdfIoQueueStop function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueStop** method prevents an I/O queue from delivering I/O requests, but the queue receives and stores new requests.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `StopComplete` [in, optional]

A pointer to a driver-supplied [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be **NULL**.

### `Context` [in, optional]

An untyped pointer to driver-supplied context information that the framework passes to the [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function. This parameter is optional and can be **NULL**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If the driver supplies an [EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state) callback function, the framework calls it after all requests that were delivered to the driver have been completed or canceled. You can modify the IRQL at which the callback runs by specifying **ExecutionLevel** in [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) at queue creation time. For more info, see the Remarks section of[*EVT_WDF_IO_QUEUE_STATE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state).

The **WdfIoQueueStop** method enables the queue to receive new requests, even if the queue was not receiving new requests before the driver called **WdfIoQueueStop**. For example, before calling **WdfIoQueueStop**, a driver might call [WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain), which causes the framework to stop adding new I/O requests to the queue. The driver's subsequent call of **WdfIoQueueStop** causes the framework to resume adding requests to the queue.

A driver must not call [WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain) after calling **WdfIoQueueStop** until it has restarted the queue by calling [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart).

For more information about the **WdfIoQueueStop** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example stops a specified I/O queue. When all requests that were delivered to the driver have been completed or canceled, it calls a driver's **EvtIoQueueStateStop** function.

```cpp
WDFCONTEXT stopContext;

stopContext = &myContext;

WdfIoQueueStop(
               queue,
               EvtIoQueueStateStop,
               stopContext
               );
```

## See also

[EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state)

[WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart)

[WdfIoQueueStopSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopsynchronously)