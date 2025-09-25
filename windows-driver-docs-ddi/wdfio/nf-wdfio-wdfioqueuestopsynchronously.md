# WdfIoQueueStopSynchronously function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueStopSynchronously** method prevents an I/O queue from delivering I/O requests, but the queue receives and stores new requests. The method returns after all delivered requests have been canceled or completed.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfIoQueueStopSynchronously** method enables the queue to receive new requests, even if the queue was not receiving new requests before the driver called **WdfIoQueueStopSynchronously**. For example, a driver might call [WdfIoQueueDrain](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuedrain), which causes the framework to stop adding new I/O requests to the queue. The driver's subsequent call of **WdfIoQueueStopSynchronously** causes the framework to resume adding requests to the queue.

Do not call **WdfIoQueueStopSynchronously** from the following queue object event callback functions, regardless of the queue with which the event callback function is associated:

[EvtIoDefault](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_default)
[EvtIoDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_device_control)
[EvtIoInternalDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_internal_device_control)
[EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read)
[EvtIoWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_write)
For more information about the **WdfIoQueueStopSynchronously** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example stops a specified queue.

```cpp
WdfIoQueueStopSynchronously(WriteQueue);
```

## See also

[WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart)

[WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop)