NET_API_STATUS NET_API_FUNCTION NetShareSetInfo(
  [in]  LMSTR   servername,
  [in]  LMSTR   netname,
  [in]  DWORD   level,
  [in]  LPBYTE  buf,
  [out] LPDWORD parm_err
);