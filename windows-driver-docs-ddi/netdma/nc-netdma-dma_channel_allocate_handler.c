DMA_CHANNEL_ALLOCATE_HANDLER DmaChannelAllocateHandler;

NTSTATUS DmaChannelAllocateHandler(
  [in]  PVOID ProviderContext,
  [in]  PNET_DMA_CHANNEL_PARAMETERS ChannelParameters,
  [in]  PVOID NetDmaChannelHandle,
  [out] PVOID *pProviderChannelContext
)
{...}