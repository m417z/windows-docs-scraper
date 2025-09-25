BOOL GetUrlCacheEntryInfoExA(
  [in]                LPCSTR                       lpszUrl,
  [in, out, optional] LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo,
  [in, out, optional] LPDWORD                      lpcbCacheEntryInfo,
  [out]               LPSTR                        lpszRedirectUrl,
  [in, out]           LPDWORD                      lpcbRedirectUrl,
                      LPVOID                       lpReserved,
  [in]                DWORD                        dwFlags
);