NET_API_STATUS NET_API_FUNCTION NetLocalGroupGetMembers(
  [in]      LPCWSTR    servername,
  [in]      LPCWSTR    localgroupname,
  [in]      DWORD      level,
  [out]     LPBYTE     *bufptr,
  [in]      DWORD      prefmaxlen,
  [out]     LPDWORD    entriesread,
  [out]     LPDWORD    totalentries,
  [in, out] PDWORD_PTR resumehandle
);