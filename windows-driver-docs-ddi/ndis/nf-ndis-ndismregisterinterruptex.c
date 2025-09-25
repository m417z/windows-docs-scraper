NDIS_STATUS NdisMRegisterInterruptEx(
  [in]  NDIS_HANDLE                              MiniportAdapterHandle,
  [in]  NDIS_HANDLE                              MiniportInterruptContext,
  [in]  PNDIS_MINIPORT_INTERRUPT_CHARACTERISTICS MiniportInterruptCharacteristics,
  [out] PNDIS_HANDLE                             NdisInterruptHandle
);