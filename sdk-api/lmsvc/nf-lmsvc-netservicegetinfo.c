NET_API_STATUS NET_API_FUNCTION NetServiceGetInfo(
  LPCWSTR servername,
  LPCWSTR service,
  DWORD   level,
  LPBYTE  *bufptr
);