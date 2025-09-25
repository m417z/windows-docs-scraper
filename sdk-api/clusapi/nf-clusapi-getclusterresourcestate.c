CLUSTER_RESOURCE_STATE GetClusterResourceState(
  [in]                HRESOURCE hResource,
  [out, optional]     LPWSTR    lpszNodeName,
  [in, out, optional] LPDWORD   lpcchNodeName,
  [out, optional]     LPWSTR    lpszGroupName,
  [in, out, optional] LPDWORD   lpcchGroupName
);