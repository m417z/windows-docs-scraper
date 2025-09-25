HRESULT UiaGetUpdatedCache(
  [in]  HUIANODE        hnode,
  [in]  UiaCacheRequest *pRequest,
  [in]  NormalizeState  normalizeState,
  [in]  UiaCondition    *pNormalizeCondition,
  [out] SAFEARRAY       **ppRequestedData,
  [out] BSTR            *ppTreeStructure
);