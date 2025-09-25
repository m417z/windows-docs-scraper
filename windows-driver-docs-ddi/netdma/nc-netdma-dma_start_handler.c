DMA_START_HANDLER DmaStartHandler;

NTSTATUS DmaStartHandler(
  [in] PVOID ProviderChannelContext,
  [in] PNET_DMA_DESCRIPTOR DescriptorVirtualAddress,
  [in] PHYSICAL_ADDRESS DescriptorPhysicalAddress,
  [in] ULONG DescriptorCount
)
{...}