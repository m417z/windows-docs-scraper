PROTOCOL_CM_ACTIVATE_VC_COMPLETE ProtocolCmActivateVcComplete;

VOID ProtocolCmActivateVcComplete(
  [in] NDIS_STATUS Status,
  [in] NDIS_HANDLE CallMgrVcContext,
  [in] PCO_CALL_PARAMETERS CallParameters
)
{...}