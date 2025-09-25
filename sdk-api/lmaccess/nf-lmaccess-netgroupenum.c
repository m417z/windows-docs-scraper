NET_API_STATUS NET_API_FUNCTION NetGroupEnum(
  [in]      LPCWSTR    servername,
  [in]      DWORD      level,
  [out]     LPBYTE     *bufptr,
  [in]      DWORD      prefmaxlen,
  [out]     LPDWORD    entriesread,
  [out]     LPDWORD    totalentries,
  [in, out] PDWORD_PTR resume_handle
);