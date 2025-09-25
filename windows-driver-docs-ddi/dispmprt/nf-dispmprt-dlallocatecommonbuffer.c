PVOID DlAllocateCommonBuffer(
  IN PVOID              DeviceHandle,
  IN PVP_DMA_ADAPTER    DlpDmaAdapter,
  IN ULONG              DesiredLength,
  OUT PPHYSICAL_ADDRESS LogicalAddress,
  IN BOOLEAN            CacheEnabled,
  OUT PVOID             Reserved
);