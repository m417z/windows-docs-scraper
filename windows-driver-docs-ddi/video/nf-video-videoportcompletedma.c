VIDEOPORT_DEPRECATED VIDEOPORT_API VP_STATUS VideoPortCompleteDma(
  [in] IN PVOID                   HwDeviceExtension,
  [in] IN PVP_DMA_ADAPTER         VpDmaAdapter,
  [in] IN PVP_SCATTER_GATHER_LIST VpScatterGather,
  [in] IN BOOLEAN                 WriteToDevice
);