PROTOCOL_CM_REG_SAP ProtocolCmRegSap;

NDIS_STATUS ProtocolCmRegSap(
  [in]  NDIS_HANDLE CallMgrAfContext,
  [in]  PCO_SAP Sap,
  [in]  NDIS_HANDLE NdisSapHandle,
  [out] PNDIS_HANDLE CallMgrSapContext
)
{...}