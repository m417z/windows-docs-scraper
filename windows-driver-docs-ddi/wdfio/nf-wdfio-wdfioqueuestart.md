# WdfIoQueueStart function

## Description

[Applies to KMDF and UMDF]

The **WdfIoQueueStart** method enables an I/O queue to start receiving and delivering new I/O requests.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If I/O requests are in the I/O queue when the driver calls **WdfIoQueueStart**, the same thread that calls **WdfIoQueueStart** can call the driver's [request handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers) before **WdfIoQueueStart** returns. Therefore, when the driver calls **WdfIoQueueStart**, it must not hold any [locks](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-locks) that the request handlers attempt to acquire. Otherwise, a deadlock can result.

For more information about the **WdfIoQueueStart** method, see [Managing I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example purges a specified I/O queue and then restarts the queue.

```cpp
WdfIoQueuePurge(
                ReadQueue,
                WDF_NO_EVENT_CALLBACK,
                WDF_NO_CONTEXT
                );
WdfIoQueueStart(ReadQueue);
```

## See also

[WdfIoQueuePurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuepurge)

[WdfIoQueueStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestop)