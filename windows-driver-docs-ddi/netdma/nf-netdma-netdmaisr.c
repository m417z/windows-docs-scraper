NET_DMA_EXPORT VOID NetDmaIsr(
  [in]  PVOID            NetDmaChannelHandle,
  [in]  PHYSICAL_ADDRESS DmaDescriptor,
  [out] PULONG           pCpuNumber
);