NTSTATUS NewSlaveDmaChannel(
  [out] PDMACHANNELSLAVE *DmaChannel,
  [in]  PUNKNOWN         OuterUnknown,
  [in]  PRESOURCELIST    ResourceList,
  [in]  ULONG            DmaIndex,
  [in]  ULONG            MaximumLength,
  [in]  BOOLEAN          DemandMode,
  [in]  DMA_SPEED        DmaSpeed
);