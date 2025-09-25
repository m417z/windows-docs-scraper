# _WDF_IO_TARGET_SENT_IO_ACTION enumeration (wdfiotarget.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TARGET_SENT_IO_ACTION** enumeration identifies the actions that the framework can take when a driver calls [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) to stop an I/O target.

## Constants

### `WdfIoTargetSentIoUndefined:0`

Reserved for system use.

### `WdfIoTargetCancelSentIo`

Before the framework stops the I/O target, it will attempt to cancel I/O requests that are in the I/O target's queue. The framework cancels all of the target queue's I/O requests, and waits for all I/O requests to complete, before [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) returns. The framework also attempts to cancel I/O requests that have left the I/O target's queue and entered lower drivers.

### `WdfIoTargetWaitForSentIoToComplete`

Before the framework stops the I/O target, it will wait for I/O requests that are in the I/O target's queue to be completed. The framework completes all of the target queue's I/O requests, and calls each request's [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, before [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) returns.

### `WdfIoTargetLeaveSentIoPending`

The framework will leave I/O requests in the I/O target's queue. The requests remain in the target's queue until the driver calls [WdfIoTargetStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstart) or the device is removed.

## Remarks

The **WDF_IO_TARGET_SENT_IO_ACTION** enumeration is used as an input parameter to the [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) method.

If your driver specifies the **WdfIoTargetWaitForSentIoToComplete** flag, the driver must not call [WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop) from a request handler, a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function, or an [EvtUsbTargetPipeReadersFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nc-wdfusb-evt_wdf_usb_readers_failed) callback function.

For the UMDF version of this enumeration, see [WDF_IO_TARGET_SENT_IO_ACTION (UMDF)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_sent_io_action).

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[WdfIoTargetStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetstop)