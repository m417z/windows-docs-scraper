NET_API_STATUS NET_API_FUNCTION NetGroupSetInfo(
  [in]  LPCWSTR servername,
  [in]  LPCWSTR groupname,
  [in]  DWORD   level,
  [in]  LPBYTE  buf,
  [out] LPDWORD parm_err
);