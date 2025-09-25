BOOL CallNamedPipeA(
  [in]  LPCSTR  lpNamedPipeName,
  [in]  LPVOID  lpInBuffer,
  [in]  DWORD   nInBufferSize,
  [out] LPVOID  lpOutBuffer,
  [in]  DWORD   nOutBufferSize,
  [out] LPDWORD lpBytesRead,
  [in]  DWORD   nTimeOut
);