NET_API_STATUS NET_API_FUNCTION NetServiceEnum(
  LPCWSTR servername,
  DWORD   level,
  LPBYTE  *bufptr,
  DWORD   prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  LPDWORD resume_handle
);