VOID WdfDmaTransactionSetChannelConfigurationCallback(
  [in]           WDFDMATRANSACTION                             DmaTransaction,
  [in, optional] PFN_WDF_DMA_TRANSACTION_CONFIGURE_DMA_CHANNEL ConfigureRoutine,
  [in, optional] PVOID                                         ConfigureContext
);