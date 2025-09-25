PROTOCOL_CM_MAKE_CALL ProtocolCmMakeCall;

NDIS_STATUS ProtocolCmMakeCall(
  [in]            NDIS_HANDLE CallMgrVcContext,
  [in, out]       PCO_CALL_PARAMETERS CallParameters,
  [in, optional]  NDIS_HANDLE NdisPartyHandle,
  [out, optional] PNDIS_HANDLE CallMgrPartyContext
)
{...}