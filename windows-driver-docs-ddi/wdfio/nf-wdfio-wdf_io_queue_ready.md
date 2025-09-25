# WDF_IO_QUEUE_READY function

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_QUEUE_READY** function returns **TRUE** if an I/O queue's state indicates that the queue is drained.

## Parameters

### `State` [in]

A [WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_state)-typed value that [WdfIoQueueGetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuegetstate) returns.

## Return value

**WDF_IO_QUEUE_READY** returns **TRUE** if the specified queue state indicates that the queue is ready. Otherwise, the function returns **FALSE**.

## Remarks

An I/O queue is ready if the queue can accept and dispatch I/O requests.

Your driver can call **WDF_IO_QUEUE_READY** after it has called [WdfIoQueueGetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuegetstate).

For more information about I/O queue states, see [WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/ne-wdfio-_wdf_io_queue_state).

#### Examples

The following code example is a routine that returns **TRUE** if a specified I/O queue is ready.

```cpp
BOOLEAN
IsQueueReady(
    IN WDFQUEUE Queue
    )
{
    WDF_IO_QUEUE_STATE queueStatus;
    queueStatus = WdfIoQueueGetState(
                                     Queue,
                                     NULL,
                                     NULL
                                     );
    return (WDF_IO_QUEUE_READY(queueStatus)) ? TRUE : FALSE;
}
```

## See also

[WDF_IO_QUEUE_DRAINED](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_drained)

[WDF_IO_QUEUE_IDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_idle)

[WDF_IO_QUEUE_PURGED](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_purged)

[WDF_IO_QUEUE_STOPPED](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdf_io_queue_stopped)