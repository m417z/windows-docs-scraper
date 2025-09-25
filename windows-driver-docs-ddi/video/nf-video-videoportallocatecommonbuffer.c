VIDEOPORT_DEPRECATED VIDEOPORT_API PVOID VideoPortAllocateCommonBuffer(
  [in]  IN PVOID              HwDeviceExtension,
  [in]  IN PVP_DMA_ADAPTER    VpDmaAdapter,
  [in]  IN ULONG              DesiredLength,
  [out] OUT PPHYSICAL_ADDRESS LogicalAddress,
  [in]  IN BOOLEAN            CacheEnabled,
  [out] OUT PVOID             Reserved
);