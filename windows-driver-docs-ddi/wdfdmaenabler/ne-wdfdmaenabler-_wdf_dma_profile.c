typedef enum _WDF_DMA_PROFILE {
  WdfDmaProfileInvalid = 0,
  WdfDmaProfilePacket,
  WdfDmaProfileScatterGather,
  WdfDmaProfilePacket64,
  WdfDmaProfileScatterGather64,
  WdfDmaProfileScatterGatherDuplex,
  WdfDmaProfileScatterGather64Duplex,
  WdfDmaProfileSystem,
  WdfDmaProfileSystemDuplex
} WDF_DMA_PROFILE;