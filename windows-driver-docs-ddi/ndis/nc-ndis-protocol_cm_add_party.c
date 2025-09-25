PROTOCOL_CM_ADD_PARTY ProtocolCmAddParty;

NDIS_STATUS ProtocolCmAddParty(
  [in]      NDIS_HANDLE CallMgrVcContext,
  [in, out] PCO_CALL_PARAMETERS CallParameters,
  [in]      NDIS_HANDLE NdisPartyHandle,
  [out]     PNDIS_HANDLE CallMgrPartyContext
)
{...}