NET_API_STATUS NET_API_FUNCTION NetShareAdd(
  [in]  LMSTR   servername,
  [in]  DWORD   level,
  [in]  LPBYTE  buf,
  [out] LPDWORD parm_err
);