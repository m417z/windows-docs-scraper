NTSTATUS NewMasterDmaChannel(
                 PDMACHANNEL   *OutDmaChannel,
  [in, optional] PUNKNOWN      OuterUnknown,
  [in]           POOL_TYPE     PoolType,
  [in, optional] PRESOURCELIST ResourceList,
  [in]           BOOLEAN       ScatterGather,
  [in]           BOOLEAN       Dma32BitAddresses,
  [in]           BOOLEAN       Dma64BitAddresses,
  [in]           BOOLEAN       IgnoreCount,
  [in]           DMA_WIDTH     DmaWidth,
  [in]           DMA_SPEED     DmaSpeed,
  [in]           ULONG         MaximumLength,
  [in]           ULONG         DmaPort
);