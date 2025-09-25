NET_API_STATUS NET_API_FUNCTION NetWkstaSetInfo(
  [in]  LMSTR   servername,
  [in]  DWORD   level,
  [in]  LPBYTE  buffer,
  [out] LPDWORD parm_err
);