NTSTATUS NewMasterDmaChannel(
  [out]          PDMACHANNEL   *DmaChannel,
  [in]           PUNKNOWN      OuterUnknown,
  [in, optional] PRESOURCELIST ResourceList,
  [in]           ULONG         MaximumLength,
  [in]           BOOLEAN       Dma32BitAddresses,
  [in]           BOOLEAN       Dma64BitAddresses,
  [in]           DMA_WIDTH     DmaWidth,
  [in]           DMA_SPEED     DmaSpeed
);