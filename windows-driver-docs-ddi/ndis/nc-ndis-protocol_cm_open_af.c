PROTOCOL_CM_OPEN_AF ProtocolCmOpenAf;

NDIS_STATUS ProtocolCmOpenAf(
  [in]  NDIS_HANDLE CallMgrBindingContext,
  [in]  PCO_ADDRESS_FAMILY AddressFamily,
  [in]  NDIS_HANDLE NdisAfHandle,
  [out] PNDIS_HANDLE CallMgrAfContext
)
{...}