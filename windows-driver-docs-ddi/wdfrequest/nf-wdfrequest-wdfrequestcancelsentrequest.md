# WdfRequestCancelSentRequest function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestCancelSentRequest** method attempts to cancel an I/O request that the caller previously submitted to an I/O target.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestCancelSentRequest** returns **TRUE** if it successfully delivers the cancel request to the driver's I/O target. This method returns **FALSE** if the request has already been completed or canceled, or if the I/O target driver has not called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver can call **WdfRequestCancelSentRequest** to attempt to cancel an I/O request that it previously had sent to an I/O target by calling [WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend).

If the request is in the I/O target's queue, the framework cancels the request. If the framework has already delivered the request to the I/O target's driver, and if that driver has called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) to enable canceling, the framework calls that driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function. If the target's driver has not called **WdfRequestMarkCancelable** or **WdfRequestMarkCancelableEx**, the request is not canceled unless the request becomes cancelable.

If the driver has registered a [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) callback function for the request, the framework calls the callback function after the request has been canceled.

Typically, if your driver calls **WdfRequestCancelSentRequest**, it must increment the request object's reference count. For more information, see [Synchronizing Cancellation of Sent Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-cancellation-of-sent-requests).

For more information about request cancellation, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

#### Examples

The following code example is from the [kmdf_fx2](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample driver. This example is an [EvtIoStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_stop) callback function. Because this driver sends each request to its I/O target, the *EvtIoStop* callback function calls **WdfRequestCancelSentRequest** if the device has been removed.

```cpp
VOID
OsrFxEvtIoStop(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN ULONG  ActionFlags
    )
{
    UNREFERENCED_PARAMETER(Queue);

    if (ActionFlags & WdfRequestStopActionSuspend) {
        WdfRequestStopAcknowledge(Request, FALSE);
    } else if (ActionFlags & WdfRequestStopActionPurge) {
        WdfRequestCancelSentRequest(Request);
    }
    return;
}
```

## See also

[CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine)

[EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel)

[WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable)

[WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex)

[WdfRequestSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestsend)