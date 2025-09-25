DWORD MprAdminDeviceEnum(
  [in]  MPR_SERVER_HANDLE hMprServer,
  [in]  DWORD             dwLevel,
  [out] LPBYTE            *lplpbBuffer,
  [out] LPDWORD           lpdwTotalEntries
);