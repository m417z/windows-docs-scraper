NET_API_STATUS NET_API_FUNCTION NetAccessEnum(
  LPCWSTR servername,
  LPCWSTR BasePath,
  DWORD   Recursive,
  DWORD   level,
  LPBYTE  *bufptr,
  DWORD   prefmaxlen,
  LPDWORD entriesread,
  LPDWORD totalentries,
  LPDWORD resume_handle
);