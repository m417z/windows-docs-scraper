BOOL CreateUrlCacheContainerA(
  [in]           LPCSTR  Name,
  [in]           LPCSTR  lpCachePrefix,
  [in, optional] LPCSTR  lpszCachePath,
  [in]           DWORD   KBCacheLimit,
  [in]           DWORD   dwContainerType,
  [in]           DWORD   dwOptions,
                 LPVOID  pvBuffer,
  [in, out]      LPDWORD cbBuffer
);