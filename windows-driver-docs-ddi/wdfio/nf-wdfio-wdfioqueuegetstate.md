# WdfIoQueueGetState function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueGetState** method returns the status of a specified I/O queue.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

### `QueueRequests` [out, optional]

A pointer to a location that receives the number of I/O requests that are currently in the I/O queue and have not been delivered to the driver. This pointer is optional and can be **NULL**.

### `DriverRequests` [out, optional]

A pointer to a location that receives the number of I/O requests that have been delivered to the driver but that the driver has not completed or canceled. This pointer is optional and can be **NULL**.

## Return value

**WdfIoQueueGetState** returns a [WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_state)-typed value, which can contain the bitwise OR of several **WDF_IO_QUEUE_STATE** enumerators.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After calling **WdfIoQueueGetState**, your driver can pass the received state value to the following functions, which are defined in *Wdfio.h*:

* [WDF_IO_QUEUE_DRAINED](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_drained), which returns **TRUE** if the queue is drained.
* [WDF_IO_QUEUE_IDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_idle), which returns **TRUE** if the queue is idle.
* [WDF_IO_QUEUE_PURGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_purged), which returns **TRUE** if the queue is purged.
* [WDF_IO_QUEUE_READY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_ready), which returns **TRUE** if the queue is ready.
* [WDF_IO_QUEUE_STOPPED](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_stopped), which returns **TRUE** if the queue is stopped.

If your driver uses the framework's [automatic synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization), the I/O queue's status will not change between the time that the **WdfIoQueueGetState** method obtains status information from the framework and the time that the method returns. Otherwise the queue's status might change before the **WdfIoQueueGetState** method returns.

For more information about the **WdfIoQueueGetState** method, see [Obtaining I/O Queue Properties](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example is a routine that returns **TRUE** if a specified I/O queue is idle.

```cpp
BOOLEAN
IsQueueIdle(
    IN WDFQUEUE Queue
    )
{
    WDF_IO_QUEUE_STATE queueStatus;
    queueStatus = WdfIoQueueGetState(
                                     Queue,
                                     NULL,
                                     NULL
                                     );
    return (WDF_IO_QUEUE_IDLE(queueStatus)) ? TRUE : FALSE;
}
```

## See also

[EvtIoQueueState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_state)

[WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_state)