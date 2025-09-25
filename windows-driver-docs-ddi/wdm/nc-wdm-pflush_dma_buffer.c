PFLUSH_DMA_BUFFER PflushDmaBuffer;

NTSTATUS PflushDmaBuffer(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PMDL Mdl,
  [in] BOOLEAN ReadOperation
)
{...}