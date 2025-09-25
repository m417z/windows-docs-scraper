PROTOCOL_CM_CLOSE_CALL ProtocolCmCloseCall;

NDIS_STATUS ProtocolCmCloseCall(
  [in]           NDIS_HANDLE CallMgrVcContext,
  [in, optional] NDIS_HANDLE CallMgrPartyContext,
  [in, optional] PVOID CloseData,
  [in, optional] UINT Size
)
{...}