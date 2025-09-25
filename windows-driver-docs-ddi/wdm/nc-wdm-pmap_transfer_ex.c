PMAP_TRANSFER_EX PmapTransferEx;

NTSTATUS PmapTransferEx(
  [in]            PDMA_ADAPTER DmaAdapter,
  [in]            PMDL Mdl,
  [in]            PVOID MapRegisterBase,
  [in]            ULONGLONG Offset,
  [in]            ULONG DeviceOffset,
  [in, out]       PULONG Length,
  [in]            BOOLEAN WriteToDevice,
  [out, optional] PSCATTER_GATHER_LIST ScatterGatherBuffer,
  [in]            ULONG ScatterGatherBufferLength,
  [in, optional]  PDMA_COMPLETION_ROUTINE DmaCompletionRoutine,
  [in, optional]  PVOID CompletionContext
)
{...}