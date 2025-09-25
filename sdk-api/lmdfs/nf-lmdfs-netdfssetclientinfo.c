NET_API_STATUS NET_API_FUNCTION NetDfsSetClientInfo(
  [in]           LPWSTR DfsEntryPath,
  [in, optional] LPWSTR ServerName,
  [in, optional] LPWSTR ShareName,
  [in]           DWORD  Level,
  [in]           LPBYTE Buffer
);