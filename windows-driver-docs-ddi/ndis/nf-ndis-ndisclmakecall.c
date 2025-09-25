NDIS_STATUS NdisClMakeCall(
  [in]            NDIS_HANDLE         NdisVcHandle,
  [in, out]       PCO_CALL_PARAMETERS CallParameters,
  [in, optional]  NDIS_HANDLE         ProtocolPartyContext,
  [out, optional] PNDIS_HANDLE        NdisPartyHandle
);