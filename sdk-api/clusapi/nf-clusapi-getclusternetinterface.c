DWORD GetClusterNetInterface(
  [in]      HCLUSTER hCluster,
  [in]      LPCWSTR  lpszNodeName,
  [in]      LPCWSTR  lpszNetworkName,
  [out]     LPWSTR   lpszInterfaceName,
  [in, out] LPDWORD  lpcchInterfaceName
);