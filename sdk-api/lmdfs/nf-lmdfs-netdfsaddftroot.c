NET_API_STATUS NET_API_FUNCTION NetDfsAddFtRoot(
  [in]           LPWSTR ServerName,
  [in]           LPWSTR RootShare,
  [in]           LPWSTR FtDfsName,
  [in, optional] LPWSTR Comment,
  [in]           DWORD  Flags
);