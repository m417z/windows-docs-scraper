DWORD MprConfigTransportCreate(
  [in]           HANDLE hMprConfig,
  [in]           DWORD  dwTransportId,
  [in, optional] LPWSTR lpwsTransportName,
  [in]           LPBYTE pGlobalInfo,
  [in]           DWORD  dwGlobalInfoSize,
  [in, optional] LPBYTE pClientInterfaceInfo,
  [in, optional] DWORD  dwClientInterfaceInfoSize,
  [in, optional] LPWSTR lpwsDLLPath,
  [out]          HANDLE *phRouterTransport
);