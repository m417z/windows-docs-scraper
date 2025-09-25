DWORD ResUtilGetCoreClusterResourcesEx(
  [in]  HCLUSTER  hClusterIn,
  [out] HRESOURCE *phClusterNameResourceOut,
  [out] HRESOURCE *phClusterQuorumResourceOut,
  [in]  DWORD     dwDesiredAccess
);