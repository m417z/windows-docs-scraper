PROTOCOL_DIRECT_OID_REQUEST_COMPLETE ProtocolDirectOidRequestComplete;

VOID ProtocolDirectOidRequestComplete(
  [in] NDIS_HANDLE ProtocolBindingContext,
  [in] PNDIS_OID_REQUEST OidRequest,
  [in] NDIS_STATUS Status
)
{...}