NET_API_STATUS NET_API_FUNCTION NetUserGetLocalGroups(
  [in]  LPCWSTR servername,
  [in]  LPCWSTR username,
  [in]  DWORD   level,
  [in]  DWORD   flags,
  [out] LPBYTE  *bufptr,
  [in]  DWORD   prefmaxlen,
  [out] LPDWORD entriesread,
  [out] LPDWORD totalentries
);