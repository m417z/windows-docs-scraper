PROTOCOL_CM_INCOMING_CALL_COMPLETE ProtocolCmIncomingCallComplete;

VOID ProtocolCmIncomingCallComplete(
  [in] NDIS_STATUS Status,
  [in] NDIS_HANDLE CallMgrVcContext,
  [in] PCO_CALL_PARAMETERS CallParameters
)
{...}