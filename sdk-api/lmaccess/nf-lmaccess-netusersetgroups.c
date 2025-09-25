NET_API_STATUS NET_API_FUNCTION NetUserSetGroups(
  [in] LPCWSTR servername,
  [in] LPCWSTR username,
  [in] DWORD   level,
  [in] LPBYTE  buf,
  [in] DWORD   num_entries
);