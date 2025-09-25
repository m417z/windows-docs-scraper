VOID SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT(
  [out] SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG *Config,
  [in]  size_t                            MaximumTransferLength,
  [in]  PHYSICAL_ADDRESS                  Address,
  [in]  DMA_WIDTH                         DmaWidth,
  [in]  PCM_PARTIAL_RESOURCE_DESCRIPTOR   DmaDescriptor
);