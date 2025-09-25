DWORD MprAdminTransportCreate(
  [in]           MPR_SERVER_HANDLE hMprServer,
  [in]           DWORD             dwTransportId,
  [in, optional] LPWSTR            lpwsTransportName,
  [in]           LPBYTE            pGlobalInfo,
  [in]           DWORD             dwGlobalInfoSize,
  [in, optional] LPBYTE            pClientInterfaceInfo,
  [in, optional] DWORD             dwClientInterfaceInfoSize,
  [in]           LPWSTR            lpwsDLLPath
);