NDIS_STATUS NdisCoOidRequest(
  [in]           NDIS_HANDLE       NdisBindingHandle,
  [in, optional] NDIS_HANDLE       NdisAfHandle,
  [in, optional] NDIS_HANDLE       NdisVcHandle,
  [in, optional] NDIS_HANDLE       NdisPartyHandle,
  [in, out]      PNDIS_OID_REQUEST OidRequest
);