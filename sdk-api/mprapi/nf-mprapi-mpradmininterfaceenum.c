DWORD MprAdminInterfaceEnum(
  [in]  MPR_SERVER_HANDLE hMprServer,
  [in]  DWORD             dwLevel,
  [out] LPBYTE            *lplpbBuffer,
  [in]  DWORD             dwPrefMaxLen,
  [out] LPDWORD           lpdwEntriesRead,
  [out] LPDWORD           lpdwTotalEntries,
  [in]  LPDWORD           lpdwResumeHandle
);