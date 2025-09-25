BOOL QueryServiceConfig2A(
  [in]            SC_HANDLE hService,
  [in]            DWORD     dwInfoLevel,
  [out, optional] LPBYTE    lpBuffer,
  [in]            DWORD     cbBufSize,
  [out]           LPDWORD   pcbBytesNeeded
);