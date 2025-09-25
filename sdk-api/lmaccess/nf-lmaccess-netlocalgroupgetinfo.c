NET_API_STATUS NET_API_FUNCTION NetLocalGroupGetInfo(
  [in]  LPCWSTR servername,
  [in]  LPCWSTR groupname,
  [in]  DWORD   level,
  [out] LPBYTE  *bufptr
);