DWORD MprAdminMIBEntryGetFirst(
  [in]  MIB_SERVER_HANDLE hMibServer,
  [in]  DWORD             dwProtocolId,
  [in]  DWORD             dwRoutingPid,
  [in]  LPVOID            lpInEntry,
  [in]  DWORD             dwInEntrySize,
  [out] LPVOID            *lplpOutEntry,
  [out] LPDWORD           lpOutEntrySize
);