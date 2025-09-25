DWORD MprAdminInterfaceTransportSetInfo(
  [in] MPR_SERVER_HANDLE hMprServer,
  [in] HANDLE            hInterface,
  [in] DWORD             dwTransportId,
  [in] LPBYTE            pInterfaceInfo,
  [in] DWORD             dwInterfaceInfoSize
);