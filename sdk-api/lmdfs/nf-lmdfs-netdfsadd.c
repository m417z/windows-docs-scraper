NET_API_STATUS NET_API_FUNCTION NetDfsAdd(
  [in]           LPWSTR DfsEntryPath,
  [in]           LPWSTR ServerName,
  [in]           LPWSTR ShareName,
  [in, optional] LPWSTR Comment,
  [in]           DWORD  Flags
);