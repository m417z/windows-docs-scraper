VOID NdisRegisterProtocol(
  [out] PNDIS_STATUS                   Status,
  [out] PNDIS_HANDLE                   NdisProtocolHandle,
  [in]  PNDIS_PROTOCOL_CHARACTERISTICS ProtocolCharacteristics,
  [in]  UINT                           CharacteristicsLength
);