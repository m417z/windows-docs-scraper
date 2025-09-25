BOOL FindNextUrlCacheEntryExW(
  [in]      HANDLE                       hEnumHandle,
  [in, out] LPINTERNET_CACHE_ENTRY_INFOW lpNextCacheEntryInfo,
  [in, out] LPDWORD                      lpcbCacheEntryInfo,
            LPVOID                       lpGroupAttributes,
            LPDWORD                      lpcbGroupAttributes,
            LPVOID                       lpReserved
);