# _WDF_IO_QUEUE_STATE enumeration (wdfio.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_QUEUE_STATE** enumeration type identifies the status of a framework queue object. The enumerators are used as bit masks.

## Constants

### `WdfIoQueueAcceptRequests:0x01`

If set, the I/O queue can accept new I/O requests from the I/O manager and requests that are forwarded by the [WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching) and [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue) (or [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue)) methods.

If not set, the framework cancels requests from the I/O manager and [WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching) and fails requests from [WdfRequestForwardToIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoioqueue) (or [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue)) with STATUS_WDF_BUSY.

### `WdfIoQueueDispatchRequests:0x02`

If set, the framework delivers the queue's requests to the driver (unless the **WdfIoQueuePnpHeld** bit is also set). If not set, the driver cannot obtain requests from the queue.

### `WdfIoQueueNoRequests:0x04`

If set, the I/O queue is empty.

### `WdfIoQueueDriverNoRequests:0x08`

If set, all requests that have been delivered to the driver have been completed.

### `WdfIoQueuePnpHeld:0x10`

If set, the framework has stopped delivering requests to the driver because the underlying device is not in its working (D0) state.

## Remarks

The WDF_IO_QUEUE_STATE enumeration type is used as the return value for the [WdfIoQueueGetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuegetstate) method.

The following functions are defined in *wdfio.h*:

## See also

[WdfIoQueueGetState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nf-wdfio-wdfioqueuegetstate)