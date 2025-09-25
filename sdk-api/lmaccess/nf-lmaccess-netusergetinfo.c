NET_API_STATUS NET_API_FUNCTION NetUserGetInfo(
  [in]  LPCWSTR servername,
  [in]  LPCWSTR username,
  [in]  DWORD   level,
  [out] LPBYTE  *bufptr
);