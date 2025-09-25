NET_API_STATUS NET_API_FUNCTION NetDfsGetInfo(
  [in]           LPWSTR DfsEntryPath,
  [in, optional] LPWSTR ServerName,
  [in, optional] LPWSTR ShareName,
  [in]           DWORD  Level,
  [out]          LPBYTE *Buffer
);