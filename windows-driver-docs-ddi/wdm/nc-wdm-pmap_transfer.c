PMAP_TRANSFER PmapTransfer;

PHYSICAL_ADDRESS PmapTransfer(
  [in]      PDMA_ADAPTER DmaAdapter,
  [in]      PMDL Mdl,
  [in]      PVOID MapRegisterBase,
  [in]      PVOID CurrentVa,
  [in, out] PULONG Length,
  [in]      BOOLEAN WriteToDevice
)
{...}