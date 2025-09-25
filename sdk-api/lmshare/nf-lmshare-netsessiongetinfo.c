NET_API_STATUS NET_API_FUNCTION NetSessionGetInfo(
  [in]  LMSTR  servername,
  [in]  LMSTR  UncClientName,
  [in]  LMSTR  username,
  [in]  DWORD  level,
  [out] LPBYTE *bufptr
);