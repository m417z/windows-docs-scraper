# _WDF_IO_TARGET_PURGE_IO_ACTION enumeration

## Description

[Applies to KMDF and UMDF]

 The
**WDF_IO_TARGET_PURGE_IO_ACTION** enumeration identifies the actions that the framework can take when a driver calls [WdfIoTargetPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetpurge) to purge an I/O target.

## Constants

### `WdfIoTargetPurgeIoUndefined:0`

Reserved for system use.

### `WdfIoTargetPurgeIoAndWait:1`

The framework attempts to cancel all of the I/O requests in the target's queue, and waits until all delivered requests are completed or canceled, before [WdfIoTargetPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetpurge) returns. If the framework receives additional requests for the queue, it completes them with a completion status value of STATUS_INVALID_DEVICE_STATE.

### `WdfIoTargetPurgeIo:2`

The framework attempts to cancel all of the target queue's I/O requests, before [WdfIoTargetPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetpurge) returns.

## Remarks

The **WDF_IO_TARGET_PURGE_IO_ACTION** enumeration is used as an input parameter to the [WdfIoTargetPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetpurge) method.

If your driver specifies the **WdfIoTargetPurgeIoAndWait** flag, the driver must not call [WdfIoTargetPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetpurge) from a request handler, a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, or an [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback function.

## See also

[WDF_IO_TARGET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_state)

[WdfIoTargetPurge](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetpurge)