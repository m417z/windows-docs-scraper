PROTOCOL_CL_MODIFY_CALL_QOS_COMPLETE ProtocolClModifyCallQosComplete;

VOID ProtocolClModifyCallQosComplete(
  [in] NDIS_STATUS Status,
  [in] NDIS_HANDLE ProtocolVcContext,
  [in] PCO_CALL_PARAMETERS CallParameters
)
{...}