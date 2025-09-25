EVT_WDF_DMA_TRANSACTION_DMA_TRANSFER_COMPLETE EvtWdfDmaTransactionDmaTransferComplete;

VOID EvtWdfDmaTransactionDmaTransferComplete(
  [in] WDFDMATRANSACTION Transaction,
  [in] WDFDEVICE Device,
  [in] WDFCONTEXT Context,
  [in] WDF_DMA_DIRECTION Direction,
  [in] DMA_COMPLETION_STATUS Status
)
{...}