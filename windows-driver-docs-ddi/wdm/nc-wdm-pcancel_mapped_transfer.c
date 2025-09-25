PCANCEL_MAPPED_TRANSFER PcancelMappedTransfer;

NTSTATUS PcancelMappedTransfer(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PVOID DmaTransferContext
)
{...}