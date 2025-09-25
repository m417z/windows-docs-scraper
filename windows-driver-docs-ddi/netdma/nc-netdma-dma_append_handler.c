DMA_APPEND_HANDLER DmaAppendHandler;

NTSTATUS DmaAppendHandler(
  [in] PVOID ProviderChannelContext,
  [in] PNET_DMA_DESCRIPTOR DescriptorVirtualAddress,
  [in] PHYSICAL_ADDRESS DescriptorPhysicalAddress,
  [in] ULONG DescriptorCount
)
{...}