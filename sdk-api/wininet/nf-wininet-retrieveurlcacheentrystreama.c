HANDLE RetrieveUrlCacheEntryStreamA(
  [in]      LPCSTR                       lpszUrlName,
  [out]     LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo,
  [in, out] LPDWORD                      lpcbCacheEntryInfo,
  [in]      BOOL                         fRandomRead,
  [in]      DWORD                        dwReserved
);