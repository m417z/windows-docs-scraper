NET_API_STATUS NET_API_FUNCTION NetUseGetInfo(
  [in]  LMSTR  UncServerName,
  [in]  LMSTR  UseName,
  [in]  DWORD  LevelFlags,
  [out] LPBYTE *bufptr
);