DWORD MprConfigInterfaceTransportGetInfo(
  [in]                HANDLE  hMprConfig,
  [in]                HANDLE  hRouterInterface,
  [in]                HANDLE  hRouterIfTransport,
  [in, out, optional] LPBYTE  *ppInterfaceInfo,
  [out, optional]     LPDWORD lpdwInterfaceInfoSize
);