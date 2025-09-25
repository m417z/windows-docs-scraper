DWORD MprAdminInterfaceTransportGetInfo(
  [in]            MPR_SERVER_HANDLE hMprServer,
  [in]            HANDLE            hInterface,
  [in]            DWORD             dwTransportId,
  [out]           LPBYTE            *ppInterfaceInfo,
  [out, optional] LPDWORD           lpdwInterfaceInfoSize
);