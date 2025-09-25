# _WDF_REQUEST_STOP_ACTION_FLAGS enumeration (wdfrequest.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_STOP_ACTION_FLAGS** enumeration type defines flags that the framework passes to a driver's [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function.

## Constants

### `WdfRequestStopActionInvalid:0`

Reserved for internal use only.

### `WdfRequestStopActionSuspend:0x01`

The framework is stopping the I/O queue because the device is leaving its working (D0) state.

### `WdfRequestStopActionPurge:0x2`

The framework is stopping the I/O queue because the device is being removed.

### `WdfRequestStopRequestCancelable:0x10000000`

The I/O request is cancelable.

## Remarks

When the framework calls a driver's [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function, it sets either the **WdfRequestStopActionSuspend** or **WdfRequestStopActionPurge** flag. If the request is cancelable, the framework also sets the **WdfRequestStopRequestCancelable** flag.

## See also

[EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop)