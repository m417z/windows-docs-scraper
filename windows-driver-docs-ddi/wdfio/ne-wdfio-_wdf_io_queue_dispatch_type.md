# _WDF_IO_QUEUE_DISPATCH_TYPE enumeration (wdfio.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_QUEUE_DISPATCH_TYPE** enumeration type identifies the request dispatching methods that can be associated with a framework queue object.

## Constants

### `WdfIoQueueDispatchInvalid:0`

Reserved for internal use.

### `WdfIoQueueDispatchSequential`

The I/O queue's requests are presented to the driver's [request handlers](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers) one at a time. The framework does not deliver the next request until a driver has called [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) to complete the current request.

### `WdfIoQueueDispatchParallel`

The framework presents requests to the driver's request handlers as soon as the requests are available.

### `WdfIoQueueDispatchManual`

The framework places requests into the queue but does not deliver them to the driver. The driver must retrieve requests from the queue by calling [WdfIoQueueRetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievenextrequest).

### `WdfIoQueueDispatchMax`

Reserved for internal use only.

## Remarks

For more information, see [Dispatching Methods for I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/dispatching-methods-for-i-o-requests).