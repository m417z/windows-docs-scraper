VOID SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION(
  [out] SERCX2_SYSTEM_DMA_RECEIVE_CONFIG                           *Config,
  [in]  size_t                                                     MaximumTransferLength,
  [in]  PHYSICAL_ADDRESS                                           Address,
  [in]  DMA_WIDTH                                                  DmaWidth,
  [in]  PCM_PARTIAL_RESOURCE_DESCRIPTOR                            DmaDescriptor,
  [in]  PFN_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION EvtSerCx2SystemDmaReceiveEnableNewDataNotification,
  [in]  PFN_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION EvtSerCx2SystemDmaReceiveCancelNewDataNotification
);