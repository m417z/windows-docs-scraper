PROTOCOL_OID_REQUEST_COMPLETE ProtocolOidRequestComplete;

VOID ProtocolOidRequestComplete(
  [in] NDIS_HANDLE ProtocolBindingContext,
  [in] PNDIS_OID_REQUEST OidRequest,
  [in] NDIS_STATUS Status
)
{...}