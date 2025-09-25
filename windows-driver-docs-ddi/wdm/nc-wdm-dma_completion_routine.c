DMA_COMPLETION_ROUTINE DmaCompletionRoutine;

void DmaCompletionRoutine(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PVOID CompletionContext,
  [in] DMA_COMPLETION_STATUS Status
)
{...}