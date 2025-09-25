NDIS_STATUS NdisMRegisterDmaChannel(
  [out] PNDIS_HANDLE          MiniportDmaHandle,
  [in]  NDIS_HANDLE           MiniportAdapterHandle,
  [in]  UINT                  DmaChannel,
  [in]  BOOLEAN               Dma32BitAddresses,
  [in]  PNDIS_DMA_DESCRIPTION DmaDescription,
  [in]  ULONG                 MaximumLength
);