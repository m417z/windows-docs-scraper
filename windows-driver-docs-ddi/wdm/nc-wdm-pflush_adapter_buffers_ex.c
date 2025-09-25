PFLUSH_ADAPTER_BUFFERS_EX PflushAdapterBuffersEx;

NTSTATUS PflushAdapterBuffersEx(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PMDL Mdl,
  [in] PVOID MapRegisterBase,
  [in] ULONGLONG Offset,
  [in] ULONG Length,
  [in] BOOLEAN WriteToDevice
)
{...}