DMA_CHANNELS_CPU_AFFINITY_HANDLER DmaChannelsCpuAffinityHandler;

NTSTATUS DmaChannelsCpuAffinityHandler(
  [in] PVOID ProviderContext,
  [in] PNET_DMA_CHANNEL_CPU_AFFINITY CpuAffinityArray,
  [in] ULONG CpuAffinityArraySize
)
{...}