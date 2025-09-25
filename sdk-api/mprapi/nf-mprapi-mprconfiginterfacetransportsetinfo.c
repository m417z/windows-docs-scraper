DWORD MprConfigInterfaceTransportSetInfo(
  [in]           HANDLE hMprConfig,
  [in]           HANDLE hRouterInterface,
  [in]           HANDLE hRouterIfTransport,
  [in, optional] LPBYTE pInterfaceInfo,
  [in, optional] DWORD  dwInterfaceInfoSize
);