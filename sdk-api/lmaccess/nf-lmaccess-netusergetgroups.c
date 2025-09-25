NET_API_STATUS NET_API_FUNCTION NetUserGetGroups(
  [in]  LPCWSTR servername,
  [in]  LPCWSTR username,
  [in]  DWORD   level,
  [out] LPBYTE  *bufptr,
  [in]  DWORD   prefmaxlen,
  [out] LPDWORD entriesread,
  [out] LPDWORD totalentries
);