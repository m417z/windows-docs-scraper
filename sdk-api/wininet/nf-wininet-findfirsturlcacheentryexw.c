HANDLE FindFirstUrlCacheEntryExW(
  [in]      LPCWSTR                      lpszUrlSearchPattern,
  [in]      DWORD                        dwFlags,
  [in]      DWORD                        dwFilter,
  [in]      GROUPID                      GroupId,
  [out]     LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo,
  [in, out] LPDWORD                      lpcbCacheEntryInfo,
  [out]     LPVOID                       lpGroupAttributes,
  [in, out] LPDWORD                      lpcbGroupAttributes,
  [in]      LPVOID                       lpReserved
);