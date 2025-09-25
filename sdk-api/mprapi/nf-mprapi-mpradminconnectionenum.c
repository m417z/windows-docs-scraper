DWORD MprAdminConnectionEnum(
  [in]  RAS_SERVER_HANDLE hRasServer,
  [in]  DWORD             dwLevel,
  [out] LPBYTE            *lplpbBuffer,
  [in]  DWORD             dwPrefMaxLen,
  [out] LPDWORD           lpdwEntriesRead,
  [out] LPDWORD           lpdwTotalEntries,
  [in]  LPDWORD           lpdwResumeHandle
);