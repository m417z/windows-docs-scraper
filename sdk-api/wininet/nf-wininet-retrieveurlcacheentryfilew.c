BOOL RetrieveUrlCacheEntryFileW(
  [in]      LPCWSTR                      lpszUrlName,
  [out]     LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo,
  [in, out] LPDWORD                      lpcbCacheEntryInfo,
  [in]      DWORD                        dwReserved
);