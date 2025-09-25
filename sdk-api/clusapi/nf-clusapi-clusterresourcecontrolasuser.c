DWORD ClusterResourceControlAsUser(
  [in]            HRESOURCE hResource,
  [in, optional]  HNODE     hHostNode,
  [in]            DWORD     dwControlCode,
  [in, optional]  LPVOID    lpInBuffer,
  [in]            DWORD     cbInBufferSize,
  [out, optional] LPVOID    lpOutBuffer,
  [in]            DWORD     cbOutBufferSize,
  [out, optional] LPDWORD   lpBytesReturned
);