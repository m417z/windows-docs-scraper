# WdfRequestUnmarkCancelable function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestUnmarkCancelable** method disables cancellation of a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestUnmarkCancelable** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid or the request is already not cancelable. |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver does not own the request. |
| **STATUS_CANCELLED** | The request has been canceled. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver can call **WdfRequestUnmarkCancelable** to disable cancellation of an I/O request, if the driver previously called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) to enable cancellation of the request.

If **WdfRequestUnmarkCancelable** returns a value other than STATUS_CANCELLED, the driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function will not be called for the request.

If the driver previously called [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable) or [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex), the driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function can call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) with a *Status* parameter of STATUS_CANCELLED. The *EvtRequestCancel* callback function does not have to call **WdfRequestUnmarkCancelable**. If the driver calls **WdfRequestComplete** outside of its *EvtRequestCancel* callback function, the driver must first call **WdfRequestUnmarkCancelable**.

However, the driver must not call **WdfRequestUnmarkCancelable** after [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) calls [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete). In the following Example section, the example stores a local copy of the request handle and then clears it when the *EvtRequestCancel* callback function calls **WdfRequestComplete**. The driver does not call **WdfRequestUnmarkCancelable** if the local copy of the request handle has been cleared. This example uses the framework's [automatic synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization) to synchronize the callback functions.

Note that calling [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) to add an additional reference to the request object does *not* enable your driver to call **WdfRequestUnmarkCancelable** after the driver's [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function calls [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete).

If **WdfRequestUnmarkCancelable** returns STATUS_CANCELLED, and then [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) completes the request, the driver must not subsequently use the request object.

If **WdfRequestUnmarkCancelable** returns STATUS_CANCELLED, the driver must not complete the request before the framework calls [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel). Otherwise, the framework might call the driver's *EvtRequestCancel* with an invalid request. For related code examples, please see [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable).

For more information about **WdfRequestUnmarkCancelable**, see [Canceling I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests).

#### Examples

The following code example provides simplified versions of the [EvtIoRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfio/nc-wdfio-evt_wdf_io_queue_io_read), [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) and [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) callback functions that the [ECHO sample driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) contains. This example shows how to call [WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable), **WdfRequestUnmarkCancelable**, and [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) in a driver that uses the framework's [automatic synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization). (The ECHO sample uses device-level synchronization.)

If your driver does not use the framework's automatic synchronization, see the two examples on [IWDFIoRequest::UnmarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-unmarkcancelable). While written for a UMDF driver, these examples demonstrate techniques you can use to manage synchronization between the cancel callback and another thread that calls the *Unmark* routine.

```cpp
VOID
  EchoEvtIoRead(
    IN WDFQUEUE  Queue,
    IN WDFREQUEST  Request,
    IN size_t  Length
    )
{
    PQUEUE_CONTEXT queueContext = QueueGetContext(Queue);

    // Prepare for read operation here.
    // (See the Echo sample driver for details.)
 ...
    // Enable cancellation.
    WdfRequestMarkCancelable(
                             Request,
                             EchoEvtRequestCancel
                             );

    // Save the request handle. We'll clear it after
    // we call WdfRequestComplete.
    queueContext->CurrentRequest = Request;
    return
}

VOID
 EchoEvtRequestCancel(
    IN WDFREQUEST  Request
    )
{
    PQUEUE_CONTEXT queueContext =
        QueueGetContext(WdfRequestGetIoQueue(Request));

    WdfRequestComplete(
                       Request,
                       STATUS_CANCELLED,
     );
    // Clear the request handle so EchEvtTimerFunc will
    // know that we called WdfRequestComplete.
    queueContext->CurrentRequest = NULL;

    return;
}

VOID
  EchoEvtTimerFunc(
    IN WDFTIMER  Timer
    )
{
    NTSTATUS  Status;
    WDFREQUEST  Request;
    WDFQUEUE  queue;
    PQUEUE_CONTEXT  queueContext;

    // Retrieve our saved copy of the request handle.
    queue = WdfTimerGetParentObject(Timer);
    queueContext = QueueGetContext(queue);
    Request = queueContext->CurrentRequest;

    // We cannot call WdfRequestUnmarkCancelable
    // after a request completes, so check here to see
    // if EchoEvtRequestCancel cleared our saved
    // request handle.
    if( Request != NULL ) {
        Status = WdfRequestUnmarkCancelable(Request);
        if(Status != STATUS_CANCELLED) {
            queueContext->CurrentRequest = NULL;
            Status = queueContext->CurrentStatus;
            WdfRequestComplete(
                               Request,
                               Status
                               );
        }
    }

    return;
}
```

## See also

[EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestMarkCancelable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelable)

[WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex)