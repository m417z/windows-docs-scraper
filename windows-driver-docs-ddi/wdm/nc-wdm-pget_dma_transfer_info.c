PGET_DMA_TRANSFER_INFO PgetDmaTransferInfo;

NTSTATUS PgetDmaTransferInfo(
  [in]      PDMA_ADAPTER DmaAdapter,
  [in]      PMDL Mdl,
  [in]      ULONGLONG Offset,
  [in]      ULONG Length,
  [in]      BOOLEAN WriteOnly,
  [in, out] PDMA_TRANSFER_INFO TransferInfo
)
{...}