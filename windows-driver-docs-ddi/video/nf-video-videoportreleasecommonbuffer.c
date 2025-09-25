VIDEOPORT_DEPRECATED VIDEOPORT_API VOID VideoPortReleaseCommonBuffer(
  [in] IN PVOID            HwDeviceExtension,
  [in] IN PVP_DMA_ADAPTER  VpDmaAdapter,
  [in] IN ULONG            Length,
  [in] IN PHYSICAL_ADDRESS LogicalAddress,
  [in] IN PVOID            VirtualAddress,
  [in] IN BOOLEAN          CacheEnabled
);