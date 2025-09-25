NET_API_STATUS NET_API_FUNCTION NetUserSetInfo(
  [in]  LPCWSTR servername,
  [in]  LPCWSTR username,
  [in]  DWORD   level,
  [in]  LPBYTE  buf,
  [out] LPDWORD parm_err
);