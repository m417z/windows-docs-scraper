DWORD MprConfigTransportGetInfo(
  [in]                HANDLE  hMprConfig,
  [in]                HANDLE  hRouterTransport,
  [in, out, optional] LPBYTE  *ppGlobalInfo,
  [out, optional]     LPDWORD lpdwGlobalInfoSize,
  [in, out, optional] LPBYTE  *ppClientInterfaceInfo,
  [out, optional]     LPDWORD lpdwClientInterfaceInfoSize,
  [in, out, optional] LPWSTR  *lplpwsDLLPath
);