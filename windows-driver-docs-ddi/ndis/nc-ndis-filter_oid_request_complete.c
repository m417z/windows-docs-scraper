FILTER_OID_REQUEST_COMPLETE FilterOidRequestComplete;

VOID FilterOidRequestComplete(
  [in] NDIS_HANDLE FilterModuleContext,
  [in] PNDIS_OID_REQUEST OidRequest,
  [in] NDIS_STATUS Status
)
{...}