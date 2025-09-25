PFND3DWDDM2_2DDI_SHADERCACHE_STORE_VALUE_CB Pfnd3dwddm22DdiShadercacheStoreValueCb;

HRESULT Pfnd3dwddm22DdiShadercacheStoreValueCb(
  D3DWDDM2_2DDI_HRTCACHESESSION hCacheSession,
  const D3DWDDM2_2DDI_SHADERCACHE_HASH *pPrecomputedHash,
  const void *pKey,
  SIZE_T KeyLen,
  const void *pValue,
  SIZE_T ValueLen
)
{...}