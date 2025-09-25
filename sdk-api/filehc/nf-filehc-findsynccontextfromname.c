FILEHC_EXPORT BOOL FindSyncContextFromName(
  [in]  PNAME_CACHE_CONTEXT pNameCache,
  [in]  LPBYTE              lpbName,
  [in]  DWORD               cbName,
  [in]  CACHE_READ_CALLBACK pfnCallback,
  [in]  LPVOID              lpvClientContext,
  [in]  HANDLE              hToken,
  [in]  ACCESS_MASK         accessMask,
  [out] FIO_CONTEXT         **ppContext
);