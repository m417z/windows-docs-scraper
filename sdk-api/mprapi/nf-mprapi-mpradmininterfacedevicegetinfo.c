DWORD MprAdminInterfaceDeviceGetInfo(
  [in]  MPR_SERVER_HANDLE hMprServer,
  [in]  HANDLE            hInterface,
  [in]  DWORD             dwIndex,
  [in]  DWORD             dwLevel,
  [out] LPBYTE            *lplpBuffer
);