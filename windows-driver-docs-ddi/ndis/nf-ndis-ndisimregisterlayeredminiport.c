NDIS_STATUS NdisIMRegisterLayeredMiniport(
  [in]  NDIS_HANDLE                    NdisWrapperHandle,
  [in]  PNDIS_MINIPORT_CHARACTERISTICS MiniportCharacteristics,
  [in]  UINT                           CharacteristicsLength,
  [out] PNDIS_HANDLE                   DriverHandle
);