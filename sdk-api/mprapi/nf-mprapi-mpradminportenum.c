DWORD MprAdminPortEnum(
  [in]  RAS_SERVER_HANDLE hRasServer,
  [in]  DWORD             dwLevel,
  [in]  HANDLE            hRasConnection,
  [out] LPBYTE            *lplpbBuffer,
  [in]  DWORD             dwPrefMaxLen,
  [out] LPDWORD           lpdwEntriesRead,
  [out] LPDWORD           lpdwTotalEntries,
  [in]  LPDWORD           lpdwResumeHandle
);