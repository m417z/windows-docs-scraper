PROTOCOL_CL_CLOSE_CALL_COMPLETE ProtocolClCloseCallComplete;

VOID ProtocolClCloseCallComplete(
  [in]           NDIS_STATUS Status,
  [in]           NDIS_HANDLE ProtocolVcContext,
  [in, optional] NDIS_HANDLE ProtocolPartyContext
)
{...}