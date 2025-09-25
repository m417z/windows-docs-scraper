NDIS_STATUS NdisAllocateCloneOidRequest(
  [in] IN NDIS_HANDLE        SourceHandle,
       IN PNDIS_OID_REQUEST  OidRequest,
  [in] IN UINT               PoolTag,
       OUT PNDIS_OID_REQUEST *ClonedOidRequest
);