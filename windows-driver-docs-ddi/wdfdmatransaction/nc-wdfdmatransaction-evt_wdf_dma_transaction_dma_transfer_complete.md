# EVT_WDF_DMA_TRANSACTION_DMA_TRANSFER_COMPLETE callback function

## Description

[Applies to KMDF only]

 A driver's *EvtDmaTransactionDmaTransferComplete* event callback function is called when the system-mode controller has completed the current DMA transfer.

## Parameters

### `Transaction` [in]

A handle to a DMA transaction object representing the [DMA transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers) that has just completed.

### `Device` [in]

A handle to the framework device object that the driver specified when it called [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `Context` [in]

The context pointer that the driver specified in a previous call to [WdfDmaTransactionSetTransferCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsettransfercompletecallback).

### `Direction` [in]

A [WDF_DMA_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmaenabler/ne-wdfdmaenabler-_wdf_dma_direction)-typed value that specifies the direction of the completing DMA transfer operation.

### `Status` [in]

A [DMA_COMPLETION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-dma_completion_status)-typed value that specifies the status of the transfer.

## Remarks

The hardware for a bus-master DMA device typically issues an interrupt when a DMA transfer is complete. The driver then completes the DMA transfer in its [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function.

However, the hardware for a system-mode DMA device does not always signal DMA transfer completion by issuing an interrupt. To receive notification of DMA transfer completion, a driver for a system-mode DMA device can instead register an *EvtDmaTransactionDmaTransferComplete* event callback function by calling [WdfDmaTransactionSetTransferCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsettransfercompletecallback).

The framework calls *EvtDmaTransactionDmaTransferComplete* after the system DMA controller has completed the transfer, once for each transfer in a transaction.

From within its *EvtDmaTransactionDmaTransferComplete* callback, the driver can call the following methods to notify the framework that the transfer has completed:

[WdfDmaTransactionDmaCompleted](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompleted)
[WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal)
[WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength)
The driver might not call one of the previous methods from *EvtDmaTransactionDmaTransferComplete*, opting instead to [create a timer object](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-timers) or schedule a DPC to complete the transfer later, as needed. After **WdfDmaTransactionDmaCompleted***Xxx* returns TRUE, indicating that no more transfers are needed to complete the DMA transaction, the driver can optionally call [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute) to initiate a subsequent transaction.

If the driver calls [WdfDmaTransactionStopSystemTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionstopsystemtransfer), the framework calls *EvtDmaTransactionDmaTransferComplete* with a *Status* value of **DmaCancelled**. In this case, the driver should call [WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal) from within *EvtDmaTransactionDmaTransferComplete*, and then can continue with request processing.

The driver must not manipulate the data buffers associated with the transaction until after **WdfDmaTransactionDmaCompleted***Xxx* has returned TRUE.

The driver can call [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease) from within *EvtDmaTransactionDmaTransferComplete* if it needs to terminate the DMA transaction.

For more information about system-mode DMA, see [Supporting System-Mode DMA](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-mode-dma).

#### Examples

To define an *EvtDmaTransactionDmaTransferComplete* callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtDmaTransactionDmaTransferComplete* callback function that is named *MyDmaTransactionDmaTransferComplete*, use the **EVT_WDF_DMA_TRANSACTION_DMA_TRANSFER_COMPLETE** type as shown in this code example:

```
EVT_WDF_DMA_TRANSACTION_DMA_TRANSFER_COMPLETE  MyDmaTransactionDmaTransferComplete;
```

Then, implement your callback function as follows.

```

_Use_decl_annotations_
VOID
MyDmaTransactionDmaTransferComplete(
    WDFDMATRANSACTION Transaction,
    WDFDEVICE /* Device */,
    WDFCONTEXT Context,
    WDF_DMA_DIRECTION /* Direction */,
    DMA_COMPLETION_STATUS DmaStatus
    )
{
    PREQUEST_CONTEXT requestContext = (PREQUEST_CONTEXT) Context;
    NTSTATUS requestStatus;
    bool overrideStatus = true;
    size_t bytesTransferred;

    if (DmaStatus == DmaComplete) {
        //
        // Normal transfer completion.  Indicate this to the framework and see
        // if there's more work to do.
        //
        if (WdfDmaTransactionDmaCompleted(Transaction, &requestStatus) == FALSE) {
            //
            // There are more DMA transfers to come.  The transaction
            // may already have been completed on another processor.
            // Return without touching it again.
            //
            goto exit;
        }

        requestStatus = STATUS_SUCCESS;
    }
    else {

        //
        // Complete the entire transaction.  But throw out the status and
        // use one derived from the DmaStatus.
        //
        WdfDmaTransactionDmaCompletedFinal(Transaction, 0, &requestStatus);

        //
        // Error or cancellation.  Indicate that this was the final transfer to
        // the framework.
        //
        if (DmaStatus == DmaError) {
            requestStatus = STATUS_DEVICE_DATA_ERROR;
        }
        else {

            //
            // Cancel status should only be triggered by timeout or cancel.  Rely on
            // someone having already set the status, which means we should lose
            // the race for BeginCompletion below.
            //
            requestStatus = STATUS_PENDING;
            overrideStatus = false;
        }
    }

    //
    // Begin completion.  There's nothing special to do here if cancel or
    // timeout got there first.
    //
    BeginCompletion(requestContext, requestStatus, overrideStatus);

    //
    // Record the number of bytes we transferred.
    //
    bytesTransferred = WdfDmaTransactionGetBytesTransferred(
                        requestContext->DmaTransaction
                        );

    WdfRequestSetInformation(requestContext->Request, bytesTransferred);

    //
    // Success, error or cancel, this was the last transfer in the
    // transaction.  Attempt to complete the request.
    //
    AttemptRequestCompletion(requestContext, true);

exit:
    return;
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
                // The timer was queued but will never run.  Drop its
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

The **EVT_WDF_DMA_TRANSACTION_DMA_TRANSFER_COMPLETE** function type is defined in the WdfDmaTransaction.h header file.
To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition.
The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_WDF_DMA_TRANSACTION_DMA_TRANSFER_COMPLETE** function type in the header file are used.
For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).
For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/cpp/code-quality/annotating-function-behavior).

## See also

[WdfDmaTransactionSetTransferCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionsettransfercompletecallback)