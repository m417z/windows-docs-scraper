DWORD MprConfigInterfaceEnum(
  [in]                HANDLE  hMprConfig,
  [in]                DWORD   dwLevel,
  [in, out]           LPBYTE  *lplpBuffer,
  [in]                DWORD   dwPrefMaxLen,
  [out]               LPDWORD lpdwEntriesRead,
  [out]               LPDWORD lpdwTotalEntries,
  [in, out, optional] LPDWORD lpdwResumeHandle
);