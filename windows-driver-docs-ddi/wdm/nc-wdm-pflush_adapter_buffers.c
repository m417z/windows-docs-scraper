PFLUSH_ADAPTER_BUFFERS PflushAdapterBuffers;

BOOLEAN PflushAdapterBuffers(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PMDL Mdl,
  [in] PVOID MapRegisterBase,
  [in] PVOID CurrentVa,
  [in] ULONG Length,
  [in] BOOLEAN WriteToDevice
)
{...}