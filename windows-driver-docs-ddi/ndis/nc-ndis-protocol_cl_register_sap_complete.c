PROTOCOL_CL_REGISTER_SAP_COMPLETE ProtocolClRegisterSapComplete;

VOID ProtocolClRegisterSapComplete(
  [in] NDIS_STATUS Status,
  [in] NDIS_HANDLE ProtocolSapContext,
  [in] PCO_SAP Sap,
  [in] NDIS_HANDLE NdisSapHandle
)
{...}