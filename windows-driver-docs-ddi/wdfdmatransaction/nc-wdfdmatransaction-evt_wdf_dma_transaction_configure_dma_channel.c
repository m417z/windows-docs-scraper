EVT_WDF_DMA_TRANSACTION_CONFIGURE_DMA_CHANNEL EvtWdfDmaTransactionConfigureDmaChannel;

BOOLEAN EvtWdfDmaTransactionConfigureDmaChannel(
  [in]           WDFDMATRANSACTION DmaTransaction,
  [in]           WDFDEVICE Device,
  [in]           PVOID Context,
  [in, optional] PMDL Mdl,
  [in]           size_t Offset,
  [in]           size_t Length
)
{...}