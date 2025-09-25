BOOL CreateUrlCacheContainerW(
  [in]           LPCWSTR Name,
  [in]           LPCWSTR lpCachePrefix,
  [in, optional] LPCWSTR lpszCachePath,
  [in]           DWORD   KBCacheLimit,
  [in]           DWORD   dwContainerType,
  [in]           DWORD   dwOptions,
                 LPVOID  pvBuffer,
  [in, out]      LPDWORD cbBuffer
);