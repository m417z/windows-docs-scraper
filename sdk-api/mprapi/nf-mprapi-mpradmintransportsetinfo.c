DWORD MprAdminTransportSetInfo(
  [in]           MPR_SERVER_HANDLE hMprServer,
  [in]           DWORD             dwTransportId,
  [in, optional] LPBYTE            pGlobalInfo,
  [in]           DWORD             dwGlobalInfoSize,
  [in, optional] LPBYTE            pClientInterfaceInfo,
  [in]           DWORD             dwClientInterfaceInfoSize
);