NET_API_STATUS NET_API_FUNCTION NetUserAdd(
  [in]  LPCWSTR servername,
  [in]  DWORD   level,
  [in]  LPBYTE  buf,
  [out] LPDWORD parm_err
);