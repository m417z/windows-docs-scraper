NET_API_STATUS NET_API_FUNCTION NetGroupGetUsers(
  [in]      LPCWSTR    servername,
  [in]      LPCWSTR    groupname,
  [in]      DWORD      level,
  [out]     LPBYTE     *bufptr,
  [in]      DWORD      prefmaxlen,
  [out]     LPDWORD    entriesread,
  [out]     LPDWORD    totalentries,
  [in, out] PDWORD_PTR ResumeHandle
);