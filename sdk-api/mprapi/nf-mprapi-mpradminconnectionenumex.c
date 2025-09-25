DWORD MprAdminConnectionEnumEx(
  [in]  RAS_SERVER_HANDLE     hRasServer,
  [in]  PMPRAPI_OBJECT_HEADER pObjectHeader,
  [in]  DWORD                 dwPreferedMaxLen,
  [out] LPDWORD               lpdwEntriesRead,
  [out] LPDWORD               lpdwTotalEntries,
  [out] PRAS_CONNECTION_EX    *ppRasConn,
  [in]  LPDWORD               lpdwResumeHandle
);