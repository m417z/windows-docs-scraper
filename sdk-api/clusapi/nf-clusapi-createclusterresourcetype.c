DWORD CreateClusterResourceType(
  [in] HCLUSTER hCluster,
  [in] LPCWSTR  lpszResourceTypeName,
  [in] LPCWSTR  lpszDisplayName,
  [in] LPCWSTR  lpszResourceTypeDll,
  [in] DWORD    dwLooksAlivePollInterval,
  [in] DWORD    dwIsAlivePollInterval
);