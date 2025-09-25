PROTOCOL_CL_INCOMING_CLOSE_CALL ProtocolClIncomingCloseCall;

VOID ProtocolClIncomingCloseCall(
  [in] NDIS_STATUS CloseStatus,
  [in] NDIS_HANDLE ProtocolVcContext,
  [in] PVOID CloseData,
  [in] UINT Size
)
{...}