DWORD MprAdminTransportGetInfo(
  [in]            MPR_SERVER_HANDLE hMprServer,
  [in]            DWORD             dwTransportId,
  [out, optional] LPBYTE            *ppGlobalInfo,
  [out, optional] LPDWORD           lpdwGlobalInfoSize,
  [out, optional] LPBYTE            *ppClientInterfaceInfo,
  [out, optional] LPDWORD           lpdwClientInterfaceInfoSize
);