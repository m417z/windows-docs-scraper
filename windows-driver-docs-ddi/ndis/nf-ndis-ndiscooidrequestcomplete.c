VOID NdisCoOidRequestComplete(
  [in]           NDIS_HANDLE       NdisAfHandle,
  [in, optional] NDIS_HANDLE       NdisVcHandle,
  [in, optional] NDIS_HANDLE       NdisPartyHandle,
  [in]           PNDIS_OID_REQUEST OidRequest,
  [in]           NDIS_STATUS       Status
);