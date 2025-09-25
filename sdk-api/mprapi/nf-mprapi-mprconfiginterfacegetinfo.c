DWORD MprConfigInterfaceGetInfo(
  [in]      HANDLE  hMprConfig,
  [in]      HANDLE  hRouterInterface,
  [in]      DWORD   dwLevel,
  [in, out] LPBYTE  *lplpBuffer,
  [out]     LPDWORD lpdwBufferSize
);