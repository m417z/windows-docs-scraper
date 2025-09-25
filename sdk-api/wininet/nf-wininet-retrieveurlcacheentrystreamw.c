HANDLE RetrieveUrlCacheEntryStreamW(
  [in]      LPCWSTR                      lpszUrlName,
  [out]     LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo,
  [in, out] LPDWORD                      lpcbCacheEntryInfo,
  [in]      BOOL                         fRandomRead,
  [in]      DWORD                        dwReserved
);