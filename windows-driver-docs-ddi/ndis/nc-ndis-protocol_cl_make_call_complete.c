PROTOCOL_CL_MAKE_CALL_COMPLETE ProtocolClMakeCallComplete;

VOID ProtocolClMakeCallComplete(
  [in]           NDIS_STATUS Status,
  [in]           NDIS_HANDLE ProtocolVcContext,
  [in, optional] NDIS_HANDLE NdisPartyHandle,
  [in]           PCO_CALL_PARAMETERS CallParameters
)
{...}