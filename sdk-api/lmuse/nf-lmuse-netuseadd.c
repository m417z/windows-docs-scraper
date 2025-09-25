NET_API_STATUS NET_API_FUNCTION NetUseAdd(
  [in]  LPTSTR  servername,
  [in]  DWORD   LevelFlags,
  [in]  LPBYTE  buf,
  [out] LPDWORD parm_err
);