NET_API_STATUS NET_API_FUNCTION NetShareGetInfo(
  [in]  LMSTR  servername,
  [in]  LMSTR  netname,
  [in]  DWORD  level,
  [out] LPBYTE *bufptr
);