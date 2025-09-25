NDIS_STATUS NdisMRegisterScatterGatherDma(
  [in]      NDIS_HANDLE              MiniportAdapterHandle,
  [in, out] PNDIS_SG_DMA_DESCRIPTION DmaDescription,
  [out]     PNDIS_HANDLE             NdisMiniportDmaHandle
);