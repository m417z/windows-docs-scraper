DWORD ClusterNetworkControl(
  [in]                HNETWORK hNetwork,
  [in, optional]      HNODE    hHostNode,
  [in]                DWORD    dwControlCode,
  [in, optional]      LPVOID   lpInBuffer,
  [in]                DWORD    nInBufferSize,
  [out, optional]     LPVOID   lpOutBuffer,
  [in]                DWORD    nOutBufferSize,
  [in, out, optional] LPDWORD  lpBytesReturned
);