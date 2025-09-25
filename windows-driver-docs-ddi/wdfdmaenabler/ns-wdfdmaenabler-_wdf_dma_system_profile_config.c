typedef struct _WDF_DMA_SYSTEM_PROFILE_CONFIG {
  ULONG                           Size;
  BOOLEAN                         DemandMode;
  BOOLEAN                         LoopedTransfer;
  DMA_WIDTH                       DmaWidth;
  PHYSICAL_ADDRESS                DeviceAddress;
  PCM_PARTIAL_RESOURCE_DESCRIPTOR DmaDescriptor;
} WDF_DMA_SYSTEM_PROFILE_CONFIG, *PWDF_DMA_SYSTEM_PROFILE_CONFIG;