DWORD MprConfigInterfaceTransportAdd(
  [in]           HANDLE hMprConfig,
  [in]           HANDLE hRouterInterface,
  [in]           DWORD  dwTransportId,
  [in, optional] LPWSTR lpwsTransportName,
  [in]           LPBYTE pInterfaceInfo,
  [in]           DWORD  dwInterfaceInfoSize,
  [out]          HANDLE *phRouterIfTransport
);