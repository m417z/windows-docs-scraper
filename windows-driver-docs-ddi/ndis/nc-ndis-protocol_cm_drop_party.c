PROTOCOL_CM_DROP_PARTY ProtocolCmDropParty;

NDIS_STATUS ProtocolCmDropParty(
  [in]           NDIS_HANDLE CallMgrPartyContext,
  [in, optional] PVOID CloseData,
  [in, optional] UINT Size
)
{...}