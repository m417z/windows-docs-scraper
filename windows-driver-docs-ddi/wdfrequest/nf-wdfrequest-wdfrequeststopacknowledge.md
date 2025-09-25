# WdfRequestStopAcknowledge function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestStopAcknowledge** method informs the framework that the driver has stopped processing a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

### `Requeue` [in]

A Boolean value that, if **TRUE**, causes the framework to requeue the request into the queue so that the framework will deliver it to the driver again. If **FALSE**, the framework does not requeue the request. For more information, see the following Remarks section.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If a driver registers an [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function for an I/O queue, the framework calls it when the queue's underlying device is leaving its working (D0) state. The framework calls the *EvtIoStop* callback function for every I/O request that the driver has not [completed](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests), including requests that the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) and those that it has [forwarded](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests) to an I/O target. The driver must complete, cancel, or postpone processing of each request by doing one of the following:

* If the driver owns the request, it can call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) to complete or cancel the request.
* If the driver has forwarded the request to an I/O target, it can call [WdfRequestCancelSentRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcancelsentrequest) to attempt to cancel the request.
* If the driver postpones processing the request, it must call **WdfRequestStopAcknowledge**.

If your driver calls **WdfRequestStopAcknowledge**, it must call this method from within its [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function.

The framework does not allow the device to leave its working (D0) state until the driver has completed, canceled, or postponed every request that an [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function receives. Potentially, this inaction can prevent a system from entering its hibernation state or another low system power state.

When a driver's [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function calls **WdfRequestStopAcknowledge**, it can set the *Requeue* parameter to **TRUE** or **FALSE**:

* Setting *Requeue* to **TRUE** causes the framework to place the request back into its I/O queue.

  When the underlying device returns to its working (D0) state, the framework will redeliver the request to the driver.
* Setting *Requeue* to **FALSE** causes the framework not to requeue the request. If the driver [owns](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-ownership) the request, ownership remains with the driver. If the driver has forwarded the request, the driver is responsible for handling the request when it is completed. The driver must stop doing any I/O processing that requires hardware access.

  When the underlying device returns to its working (D0) state, the framework will call the driver's [EvtIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_resume) callback function, so that the driver can continue processing the request.

If the driver had previously called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex), it must call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable) before calling **WdfRequestStopAcknowledge** with *Requeue* set to **TRUE**.

Before calling **WdfRequestStopAcknowledge**, the driver's [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function must stop all processing of the I/O request that requires accessing the underlying device, because the device is about to enter a low-power state.

For more information about the **WdfRequestStopAcknowledge** method, see [Using Power-Managed I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-power-managed-i-o-queues).

#### Examples

If a driver calls **WdfRequestStopAcknowledge** with *Requeue* set to **TRUE**, it must previously call [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable).

The following code example is an [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function that checks to see if a received request is cancelable and, if it is, calls [WdfRequestUnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestunmarkcancelable). If **WdfRequestUnmarkCancelable** returns STATUS_CANCELLED, the example just returns because the driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function will handle the request. Otherwise, the example calls **WdfRequestStopAcknowledge** and specifies **TRUE** so that the framework requeues the request when the underlying device returns to its working (D0) state.

```cpp
VOID
MyEvtIoStop(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN ULONG  ActionFlags
    )
{
    NTSTATUS status;

    // TODO: Take steps here to suspend and, if necessary, roll back any processing that has already occurred on this request

    if (ActionFlags & WdfRequestStopRequestCancelable) {
        status = WdfRequestUnmarkCancelable(Request);
        if (status == STATUS_CANCELLED) {
            return;
        }
    }

    // Inform framework that driver is postponing processing, cause framework to redeliver request when device returns to D0

    WdfRequestStopAcknowledge(Request, TRUE);
}
```
Typically, if a driver calls **WdfRequestStopAcknowledge** with *Requeue* set to **FALSE**, it leaves the request cancelable.

The following code example is an [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function that calls **WdfRequestStopAcknowledge** and specifies **FALSE** so that the framework eventually calls the driver's [EvtIoResume](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_resume) callback function, where the driver resumes processing of the request.

You might use code like this if it is acceptable to halt processing of a specific request and continue it later, rather than having the request redelivered and restarting processing from the beginning.

```cpp
VOID
MyEvtIoStop(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN ULONG  ActionFlags
    )
{

    //TODO: Take steps here to suspend processing of the request so it can be resumed when power returns
	
    // Acknowledge the stop, but leave the request under driver's ownership.
    // Provide a corresponding EvtIoResume handler to resume processing when power returns

    WdfRequestStopAcknowledge(Request, FALSE);
}
```

## See also

[EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop)

[EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)