DWORD MprConfigTransportSetInfo(
  [in]           HANDLE hMprConfig,
  [in]           HANDLE hRouterTransport,
  [in, optional] LPBYTE pGlobalInfo,
  [in, optional] DWORD  dwGlobalInfoSize,
  [in, optional] LPBYTE pClientInterfaceInfo,
  [in, optional] DWORD  dwClientInterfaceInfoSize,
  [in, optional] LPWSTR lpwsDLLPath
);