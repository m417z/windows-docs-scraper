FILTER_DIRECT_OID_REQUEST_COMPLETE FilterDirectOidRequestComplete;

VOID FilterDirectOidRequestComplete(
  [in] NDIS_HANDLE FilterModuleContext,
  [in] PNDIS_OID_REQUEST OidRequest,
  [in] NDIS_STATUS Status
)
{...}