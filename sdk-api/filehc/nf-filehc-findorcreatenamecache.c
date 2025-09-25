FILEHC_EXPORT PNAME_CACHE_CONTEXT FindOrCreateNameCache(
  [in] LPSTR                  lpstrName,
  [in] CACHE_KEY_COMPARE      pfnKeyCompare,
  [in] CACHE_KEY_HASH         pfnKeyHash,
  [in] CACHE_DESTROY_CALLBACK pfnKeyDestroy,
  [in] CACHE_DESTROY_CALLBACK pfnDataDestroy
);