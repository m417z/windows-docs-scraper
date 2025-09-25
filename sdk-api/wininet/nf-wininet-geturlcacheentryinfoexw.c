BOOL GetUrlCacheEntryInfoExW(
  [in]                LPCWSTR                      lpszUrl,
  [in, out, optional] LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo,
  [in, out, optional] LPDWORD                      lpcbCacheEntryInfo,
  [out]               LPWSTR                       lpszRedirectUrl,
  [in, out]           LPDWORD                      lpcbRedirectUrl,
                      LPVOID                       lpReserved,
  [in]                DWORD                        dwFlags
);