NET_API_STATUS NET_API_FUNCTION NetUserEnum(
  [in]      LPCWSTR servername,
  [in]      DWORD   level,
  [in]      DWORD   filter,
  [out]     LPBYTE  *bufptr,
  [in]      DWORD   prefmaxlen,
  [out]     LPDWORD entriesread,
  [out]     LPDWORD totalentries,
  [in, out] PDWORD  resume_handle
);