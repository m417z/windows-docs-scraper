NET_API_STATUS NET_API_FUNCTION NetDfsAddRootTarget(
  [in]           LPWSTR pDfsPath,
  [in, optional] LPWSTR pTargetPath,
  [in]           ULONG  MajorVersion,
  [in, optional] LPWSTR pComment,
  [in]           ULONG  Flags
);