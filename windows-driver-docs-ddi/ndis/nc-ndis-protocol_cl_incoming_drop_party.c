PROTOCOL_CL_INCOMING_DROP_PARTY ProtocolClIncomingDropParty;

VOID ProtocolClIncomingDropParty(
  [in] NDIS_STATUS DropStatus,
  [in] NDIS_HANDLE ProtocolPartyContext,
  [in] PVOID CloseData,
  [in] UINT Size
)
{...}