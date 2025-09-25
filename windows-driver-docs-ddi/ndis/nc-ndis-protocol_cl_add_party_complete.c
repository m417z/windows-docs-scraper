PROTOCOL_CL_ADD_PARTY_COMPLETE ProtocolClAddPartyComplete;

VOID ProtocolClAddPartyComplete(
  [in] NDIS_STATUS Status,
  [in] NDIS_HANDLE ProtocolPartyContext,
  [in] NDIS_HANDLE NdisPartyHandle,
  [in] PCO_CALL_PARAMETERS CallParameters
)
{...}