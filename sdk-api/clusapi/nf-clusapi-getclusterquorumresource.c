DWORD GetClusterQuorumResource(
  [in]      HCLUSTER hCluster,
  [out]     LPWSTR   lpszResourceName,
  [in, out] LPDWORD  lpcchResourceName,
  [out]     LPWSTR   lpszDeviceName,
  [in, out] LPDWORD  lpcchDeviceName,
  [out]     LPDWORD  lpdwMaxQuorumLogSize
);