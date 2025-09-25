# WdfIoQueueStopAndPurgeSynchronously function

## Description

[Applies to KMDF and UMDF]

 The **WdfIoQueueStopAndPurgeSynchronously** method
prevents an I/O queue from delivering new I/O requests and causes the framework to cancel existing unprocessed requests and driver-owned cancellable requests, but the queue receives and stores new requests.

## Parameters

### `Queue` [in]

A handle to a framework queue object.

## Remarks

This method returns after all the unprocessed and driver-owned requests (not including requests added to the queue after this call is made) are completed or canceled. If new requests are inserted while **WdfIoQueueStopAndPurgeSynchronously** is in progress, these new requests are not delivered until driver calls [WdfIoQueueStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestart).

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfIoQueueStopAndPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuestopandpurge)