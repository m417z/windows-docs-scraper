# WdfDmaTransactionStopSystemTransfer function

## Description

[Applies to KMDF only]

 The
**WdfDmaTransactionStopSystemTransfer** method attempts to stop a system-mode DMA transfer after the framework has called [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma).

## Parameters

### `DmaTransaction` [in]

A handle to an initialized DMA transaction object.

## Remarks

Only a driver that uses system-mode DMA should call **WdfDmaTransactionStopSystemTransfer**.

A driver using bus-mastering DMA is responsible for programming its own dedicated DMA controller. In the event of a request cancellation, timeout, or device error, the driver can program the DMA controller to stop transferring data.

In contrast, a driver using system-mode DMA must rely on the hardware abstraction layer (HAL) to program the shared DMA controller. When a driver calls **WdfDmaTransactionStopSystemTransfer**, the framework notifies the HAL that the transfer must be stopped and returns immediately.

The framework next calls the driver's [EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete) callback function, if the driver has provided one. If not, the framework returns FALSE when the driver next calls [WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted).

If your driver calls this method on an operating system earlier than Windows 8, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error.

 For more information about system-mode DMA, see [Supporting System-Mode DMA](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-mode-dma).

 For more information about canceling DMA transactions, see [Canceling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-dma-transactions).

#### Examples

The following code example shows how a driver might call **WdfDmaTransactionStopSystemTransfer** from an [EvtTimerFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftimer/nc-wdftimer-evt_wdf_timer) event callback function that it registers to be called if an I/O request times out.

```cpp
VOID
MyTimerFunc(
    __in WDFTIMER Timer
    )
{
    WDFREQUEST request = (WDFREQUEST) WdfTimerGetParentObject(Timer);
    PREQUEST_CONTEXT requestContext = GetRequestContext(request);

    //
    // Begin the completion process.  If we're the first to get here
    // then stop the DMA transfer.  The dma completion routine will
    // take care of running down cancellation.
    //
    if (BeginCompletion(requestContext, STATUS_IO_TIMEOUT, false)) {
        WdfDmaTransactionStopSystemTransfer(requestContext->DmaTransaction);
    }

    AttemptRequestCompletion(requestContext, false);
}

bool
BeginCompletion(
    __in PREQUEST_CONTEXT  RequestContext,
    __in NTSTATUS          CompletionStatus,
    __in bool              ForceStatusUpdate
    )
{
    bool completionStarted;

    //
    // Grab the object lock and mark the beginning of
    // completion.
    //
    WdfSpinLockAcquire(RequestContext->Lock);

    completionStarted = RequestContext->CompletionStarted;
    RequestContext->CompletionStarted = true;

    if ((completionStarted == false) ||
        (ForceStatusUpdate == true)) {
        RequestContext->CompletionStatus = CompletionStatus;
    }

    WdfSpinLockRelease(RequestContext->Lock);

    return !completionStarted;
}

VOID
AttemptRequestCompletion(
    __in PREQUEST_CONTEXT RequestContext,
    __in bool TransferComplete
    )
{
    LONG refCount;

    NT_ASSERTMSG("No thread has begun completion",
                 RequestContext->CompletionStarted == true);

    if (TransferComplete) {
        //
        // Unmark the request cancelable.  If that succeeds then drop the cancel reference
        //
        if (WdfRequestUnmarkCancelable(RequestContext->Request) == STATUS_SUCCESS) {
            refCount = InterlockedDecrement(&(RequestContext->CompletionRefCount));
            NT_ASSERTMSGW(L"Reference count should not have gone to zero yet",
                          refCount != 0);
        }

        //
        // Stop the timer if it's been started.
        //
        if (RequestContext->TimerStarted == true) {
            if (WdfTimerStop(RequestContext->Timer, FALSE) == TRUE) {
                //
                // The timer was queued but won't ever run.  Drop its
                // reference count.
                //
                refCount = InterlockedDecrement(&RequestContext->CompletionRefCount);
                NT_ASSERTMSG("Completion reference count should not reach zero until "
                             L"this routine calls AttemptRequestCompletion",
                             refCount > 0);
            }
        }
    }

    //
    // Drop this caller's reference.  If that was the last one then
    // complete the request.
    //
    refCount = InterlockedDecrement(&(RequestContext->CompletionRefCount));

    if (refCount == 0) {
        NT_ASSERTMSGW(L"Execution reference was released, but execution "
                      L"path did not set a completion status for the "
                      L"request",
                      RequestContext->CompletionStatus != STATUS_PENDING);

        //
        // Timers are disposed of at passive level.  If we leave it attached to
        // the request then we can hit a verifier issue, since the request
        // needs to be immediately disposable at dispatch-level.
        //
        // Delete the timer now so that we can complete the request safely.
        // At this point the timer has either expired or been successfully
        // cancelled so there's no race with the timer routine.
        //
        if (RequestContext->Timer != NULL) {
            WdfObjectDelete(RequestContext->Timer);
            RequestContext->Timer = NULL;
        }

        WdfRequestComplete(RequestContext->Request,
                           RequestContext->CompletionStatus);
    }
}

```
The following code example shows how a driver might call **WdfDmaTransactionStopSystemTransfer** from an [EvtRequestCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_cancel) callback function. The driver previously called [WdfRequestMarkCancelableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestmarkcancelableex) from its I/O request handler to register the callback.

```cpp
VOID
MyRequestCancel(
    __in WDFREQUEST Request
    )
{
    PREQUEST_CONTEXT requestContext = GetRequestContext(Request);
    LONG oldValue;

    //
    // Start completion
    //

    if (BeginCompletion(requestContext, STATUS_CANCELLED, false)) {

        //
        // Cancel the DMA transaction.
        //
        if (WdfDmaTransactionCancel(requestContext->DmaTransaction) == TRUE) {
            //
            // The transaction was stopped before EvtProgramDma could be
            // called.  Drop the I/O reference.
            //
            oldValue = InterlockedDecrement(&requestContext->CompletionRefCount);
            NT_ASSERTMSG("Completion reference count should not reach zero until "
                         L"this routine calls AttemptRequestCompletion",
                         oldValue > 0);
            NT_ASSERTMSG("Completion status should be cancelled",
                         requestContext->CompletionStatus == STATUS_CANCELLED);
        }
        else {
            //
            // The transaction couldn't be stopped before EvtProgramDma.
            // Stop any running system DMA transfer.
            //
            WdfDmaTransactionStopSystemTransfer(requestContext->DmaTransaction);
        }
    }

    AttemptRequestCompletion(requestContext, false);
}

```

## See also

[WdfDmaTransactionCancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncancel)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)