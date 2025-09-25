# WdfDmaTransactionDmaCompleted function

## Description

[Applies to KMDF only]

The **WdfDmaTransactionDmaCompleted** method notifies the framework that a device's DMA transfer operation is completed.

## Parameters

### `DmaTransaction` [in]

A handle to a DMA transaction object that the driver obtained from a previous call to [WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate).

### `Status` [out]

A pointer to a location that receives the status of the DMA transfer. For more information, see the following Remarks section.

## Return value

**WdfDmaTransactionDmaCompleted** returns **FALSE** and *Status* receives STATUS_MORE_PROCESSING_REQUIRED if additional transfers are needed to complete the DMA transaction. The method returns **TRUE** if no additional transfers are required.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Framework-based drivers must call one of the following methods whenever a [DMA transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers) is complete:

* **WdfDmaTransactionDmaCompleted**
* [WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength)
* [WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal)

Typically, drivers call these methods from within an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) event callback function, after a device interrupt indicates the completion of a DMA transfer operation. A driver for a system-mode DMA device might call these methods from within an [EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete) event callback function.

The framework might divide a [DMA transaction](https://learn.microsoft.com/windows-hardware/drivers/wdf/dma-transactions-and-dma-transfers) into several DMA transfer operations. Therefore, the driver must examine the method's return value to determine if additional transfers are required.

If the method returns **FALSE**, the *Status* location receives STATUS_MORE_PROCESSING_REQUIRED and additional DMA operations are required to complete the transaction. Typically, the [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) event callback function does nothing else at this point. Instead, the framework calls the driver's [EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma) event callback function, so the callback function can begin the next transfer.

If the method returns **TRUE**, no more transfers will occur for the specified transaction. In this case, a *Status* value of STATUS_SUCCESS means that the framework did not encounter any errors and the DMA transaction is complete.

If the driver calls [WdfDmaTransactionStopSystemTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionstopsystemtransfer) before calling **WdfDmaTransactionDmaCompleted**, **WdfDmaTransactionDmaCompleted** returns **TRUE** and a *Status* value of **STATUS_CANCELLED**.

For transactions that were set for [single transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/), **WdfDmaTransactionDmaCompleted** returns **TRUE** and a *Status* value of **STATUS_WDF_TOO_MANY_TRANSFERS** if the hardware fails to complete the transaction in a single transfer, even though initialization succeeded.
This could happen for hardware that reports residual transfers for each DMA operation. For example, the driver programs the device to write 64KB, but the device writes only 60KB.
In this case, the driver might repeat the DMA operation or reset the device.

Any other value for *Status* means that the framework detected an error and the DMA transaction might not have been completed.

When **WdfDmaTransactionDmaCompleted** returns **TRUE**, the driver typically does the following:

* Calls [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) or [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease) to delete or reuse the transaction object, respectively.
* Completes the I/O request, if the DMA transaction is associated with an I/O request. (Drivers complete requests by calling [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) or [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation).)

For more information about completing DMA transfers, see [Completing a DMA Transfer](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-a-dma-transfer).

#### Examples

The following code example is from the [AMCC5933](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example shows an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function. The example notifies the framework that a DMA transfer has completed. If the framework indicates that this transfer is the last one for the DMA transaction, the code deletes the DMA transaction object and completes the associated I/O request.

```cpp
VOID
AmccPciEvtInterruptDpc(
    IN WDFINTERRUPT  WdfInterrupt,
    IN WDFOBJECT  WdfDevice
    )
{
    PAMCC_DEVICE_EXTENSION  devExt;
    WDFREQUEST  request;
    REQUEST_CONTEXT  *transfer;
    NTSTATUS  status;
    size_t  transferred;
    BOOLEAN  transactionComplete;

    UNREFERENCED_PARAMETER( WdfInterrupt );

    //
    // Retrieve request and transfer.
    //
    devExt = AmccPciGetDevExt(WdfDevice);
    request  = devExt->CurrentRequest;
    transfer = GetRequestContext(request);

    //
    // Check to see if the request has been canceled.
    //
    if (WdfRequestIsCanceled(request)) {
        TraceEvents(
                    TRACE_LEVEL_ERROR,
                    AMCC_TRACE_IO,
                    "Aborted DMA transaction 0x%p",
                    request
                    );
        WdfObjectDelete( transfer->DmaTransaction );
        devExt->CurrentRequest = NULL;
        WdfRequestComplete(
                           request,
                           STATUS_CANCELLED
                           );
        return;
    }

    //
    // Notify the framework that a DMA transfer has completed.
    //
    transactionComplete = WdfDmaTransactionDmaCompleted(
                                                    transfer->DmaTransaction,
                                                    &status
                                                    );
    if (transactionComplete) {
        ASSERT(status != STATUS_MORE_PROCESSING_REQUIRED);

        //
        // No more data. The request is complete.
        //
        TraceEvents(
                    TRACE_LEVEL_INFORMATION,
                    AMCC_TRACE_IO,
                    "Request %p completed: status %X",
                    request,
                    status
                    );

        //
        // Get the byte count.
        //
        transferred =
                WdfDmaTransactionGetBytesTransferred(transfer->DmaTransaction);

        TraceEvents(
                    TRACE_LEVEL_INFORMATION,
                    AMCC_TRACE_IO,
                    "Bytes transferred %d",
                    (int) transferred
                    );

        //
        // Delete this DmaTransaction object.
        //
        WdfObjectDelete(transfer->DmaTransaction);

        //
        // Clean up the device context for this request.
        //
        devExt->CurrentRequest = NULL;

        //
        // Complete this I/O request.
        //
        WdfRequestCompleteWithInformation(
                                          request,
                                          status,
                                          (NT_SUCCESS(status)) ? transferred : 0
                                          );
    }
}
```

## See also

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[EvtProgramDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_program_dma)

[WdfDmaTransactionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioncreate)

[WdfDmaTransactionDmaCompletedFinal](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedfinal)

[WdfDmaTransactionDmaCompletedWithLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactiondmacompletedwithlength)

[WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease)

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)

[WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)