NET_API_STATUS NET_API_FUNCTION NetGroupSetUsers(
  [in] LPCWSTR servername,
  [in] LPCWSTR groupname,
  [in] DWORD   level,
  [in] LPBYTE  buf,
  [in] DWORD   totalentries
);