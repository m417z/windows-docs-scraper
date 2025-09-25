DWORD GetClusterInformation(
  [in]            HCLUSTER             hCluster,
  [out]           LPWSTR               lpszClusterName,
  [in, out]       LPDWORD              lpcchClusterName,
  [out, optional] LPCLUSTERVERSIONINFO lpClusterInfo
);