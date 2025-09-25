NET_API_STATUS NET_API_FUNCTION NetUseEnum(
  [in]      LMSTR   UncServerName,
  [in]      DWORD   LevelFlags,
  [out]     LPBYTE  *BufPtr,
  [in]      DWORD   PreferedMaximumSize,
  [out]     LPDWORD EntriesRead,
  [out]     LPDWORD TotalEntries,
  [in, out] LPDWORD ResumeHandle
);