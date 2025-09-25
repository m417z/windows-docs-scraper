FIO_CONTEXT * CacheCreateFile(
  [in] LPSTR                  lpstrName,
  [in] FCACHE_CREATE_CALLBACK pfnCallBack,
  [in] LPVOID                 lpv,
  [in] BOOL                   fAsyncContext
);