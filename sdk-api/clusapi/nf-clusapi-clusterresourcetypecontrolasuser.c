DWORD ClusterResourceTypeControlAsUser(
  [in]            HCLUSTER hCluster,
  [in]            LPCWSTR  lpszResourceTypeName,
  [in, optional]  HNODE    hHostNode,
  [in]            DWORD    dwControlCode,
  [in, optional]  LPVOID   lpInBuffer,
  [in]            DWORD    nInBufferSize,
  [out, optional] LPVOID   lpOutBuffer,
  [in]            DWORD    nOutBufferSize,
  [out, optional] LPDWORD  lpBytesReturned
);