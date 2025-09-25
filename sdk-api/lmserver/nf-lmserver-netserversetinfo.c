NET_API_STATUS NET_API_FUNCTION NetServerSetInfo(
  [in]  LMSTR   servername,
  [in]  DWORD   level,
  [in]  LPBYTE  buf,
  [out] LPDWORD ParmError
);