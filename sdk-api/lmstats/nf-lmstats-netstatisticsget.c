NET_API_STATUS NET_API_FUNCTION NetStatisticsGet(
  [in]  LPTSTR ServerName,
  [in]  LPTSTR Service,
  [in]  DWORD  Level,
  [in]  DWORD  Options,
  [out] LPBYTE *Buffer
);