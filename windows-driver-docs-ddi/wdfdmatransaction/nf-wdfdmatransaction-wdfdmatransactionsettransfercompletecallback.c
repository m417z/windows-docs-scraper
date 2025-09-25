VOID WdfDmaTransactionSetTransferCompleteCallback(
  [in]           WDFDMATRANSACTION                             DmaTransaction,
  [in, optional] PFN_WDF_DMA_TRANSACTION_DMA_TRANSFER_COMPLETE DmaCompletionRoutine,
  [in, optional] PVOID                                         DmaCompletionContext
);