BOOL FindNextUrlCacheEntryExA(
  [in]      HANDLE                       hEnumHandle,
  [in, out] LPINTERNET_CACHE_ENTRY_INFOA lpNextCacheEntryInfo,
  [in, out] LPDWORD                      lpcbCacheEntryInfo,
            LPVOID                       lpGroupAttributes,
            LPDWORD                      lpcbGroupAttributes,
            LPVOID                       lpReserved
);