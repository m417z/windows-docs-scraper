NDIS_STATUS NdisClAddParty(
  [in]      NDIS_HANDLE         NdisVcHandle,
  [in]      NDIS_HANDLE         ProtocolPartyContext,
  [in, out] PCO_CALL_PARAMETERS CallParameters,
  [out]     PNDIS_HANDLE        NdisPartyHandle
);