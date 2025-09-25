typedef struct _SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG {
  ULONG                                                 Size;
  size_t                                                MaximumTransferLength;
  size_t                                                MinimumTransactionLength;
  ULONG                                                 DmaAlignment;
  ULONG                                                 MaximumScatterGatherFragments;
  DMA_WIDTH                                             DmaWidth;
  PHYSICAL_ADDRESS                                      DeviceAddress;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR                       DmaDescriptor;
  ULONG                                                 MinimumTransferUnitOverride;
  BOOLEAN                                               Exclusive;
  PFN_SERCX2_SYSTEM_DMA_TRANSMIT_INITIALIZE_TRANSACTION EvtSerCx2SystemDmaTransmitInitializeTransaction;
  PFN_SERCX2_SYSTEM_DMA_TRANSMIT_CLEANUP_TRANSACTION    EvtSerCx2SystemDmaTransmitCleanupTransaction;
  PFN_SERCX2_SYSTEM_DMA_TRANSMIT_CONFIGURE_DMA_CHANNEL  EvtSerCx2SystemDmaTransmitConfigureDmaChannel;
  PFN_SERCX2_SYSTEM_DMA_TRANSMIT_DRAIN_FIFO             EvtSerCx2SystemDmaTransmitDrainFifo;
  PFN_SERCX2_SYSTEM_DMA_TRANSMIT_CANCEL_DRAIN_FIFO      EvtSerCx2SystemDmaTransmitCancelDrainFifo;
  PFN_SERCX2_SYSTEM_DMA_TRANSMIT_PURGE_FIFO             EvtSerCx2SystemDmaTransmitPurgeFifo;
} SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG, *PSERCX2_SYSTEM_DMA_TRANSMIT_CONFIG;