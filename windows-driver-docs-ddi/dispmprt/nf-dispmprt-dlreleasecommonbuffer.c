VOID DlReleaseCommonBuffer(
  IN PVOID            DeviceHandle,
  IN PVP_DMA_ADAPTER  DlpDmaAdapter,
  IN ULONG            Length,
  IN PHYSICAL_ADDRESS LogicalAddress,
  IN PVOID            VirtualAddress,
  IN BOOLEAN          CacheEnabled
);