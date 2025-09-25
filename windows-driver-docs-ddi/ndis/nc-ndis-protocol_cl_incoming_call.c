PROTOCOL_CL_INCOMING_CALL ProtocolClIncomingCall;

NDIS_STATUS ProtocolClIncomingCall(
  [in]      NDIS_HANDLE ProtocolSapContext,
  [in]      NDIS_HANDLE ProtocolVcContext,
  [in, out] PCO_CALL_PARAMETERS CallParameters
)
{...}