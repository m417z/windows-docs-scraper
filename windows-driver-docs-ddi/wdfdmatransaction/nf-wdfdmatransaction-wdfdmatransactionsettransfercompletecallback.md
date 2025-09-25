# WdfDmaTransactionSetTransferCompleteCallback function

## Description

[Applies to KMDF only]

 The **WdfDmaTransactionSetTransferCompleteCallback** method registers a transfer completion event callback function for a system-mode DMA transaction.

## Parameters

### `DmaTransaction` [in]

A handle to an initialized DMA transaction object for which to set or clear the transfer completion callback.

### `DmaCompletionRoutine` [in, optional]

A pointer to the driver's [EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete) event callback function, or NULL to clear a previously set callback function.

### `DmaCompletionContext` [in, optional]

A pointer to a buffer containing the driver-specified context to be provided to the driver's [EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete) event callback function, or NULL.

## Remarks

The driver calls this method to set a completion routine that the framework calls after the system DMA controller completes a transfer. The framework calls the driver's [EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete) callback once for each transfer in the transaction.

Typically from within an [I/O queue event callback function](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers), a driver performs the following steps, in this order:

1. Calls [WdfDmaTransactionInitializeUsingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingrequest), [WdfDmaTransactionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitialize), or [WdfDmaTransactionInitializeUsingOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactioninitializeusingoffset) to initialize the transaction object.
2. Calls **WdfDmaTransactionSetTransferCompleteCallback** on the transaction object.
3. Calls [WdfDmaTransactionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionexecute).

If the driver has specified an [EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete) event callback function by calling **WdfDmaTransactionSetTransferCompleteCallback** and the driver subsequently calls [WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease), the callback is cleared.

**WdfDmaTransactionSetTransferCompleteCallback** can only be used with a DMA enabler that specifies a system-mode DMA profile.

If your driver calls this method on an operating system earlier than Windows 8, [the framework's verifier](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kmdf-verifier) reports an error.

## See also

[EvtDmaTransactionDmaTransferComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nc-wdfdmatransaction-evt_wdf_dma_transaction_dma_transfer_complete)

[WdfDmaTransactionRelease](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdmatransaction/nf-wdfdmatransaction-wdfdmatransactionrelease)