typedef struct _SERCX2_SYSTEM_DMA_RECEIVE_CONFIG {
  ULONG                                                      Size;
  size_t                                                     MaximumTransferLength;
  size_t                                                     MinimumTransactionLength;
  ULONG                                                      DmaAlignment;
  ULONG                                                      MaximumScatterGatherFragments;
  DMA_WIDTH                                                  DmaWidth;
  PHYSICAL_ADDRESS                                           DeviceAddress;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR                            DmaDescriptor;
  ULONG                                                      MinimumTransferUnitOverride;
  BOOLEAN                                                    Exclusive;
  PFN_SERCX2_SYSTEM_DMA_RECEIVE_INITIALIZE_TRANSACTION       EvtSerCx2SystemDmaReceiveInitializeTransaction;
  PFN_SERCX2_SYSTEM_DMA_RECEIVE_CLEANUP_TRANSACTION          EvtSerCx2SystemDmaReceiveCleanupTransaction;
  PFN_SERCX2_SYSTEM_DMA_RECEIVE_CONFIGURE_DMA_CHANNEL        EvtSerCx2SystemDmaReceiveConfigureDmaChannel;
  PFN_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION EvtSerCx2SystemDmaReceiveEnableNewDataNotification;
  PFN_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION EvtSerCx2SystemDmaReceiveCancelNewDataNotification;
} SERCX2_SYSTEM_DMA_RECEIVE_CONFIG, *PSERCX2_SYSTEM_DMA_RECEIVE_CONFIG;