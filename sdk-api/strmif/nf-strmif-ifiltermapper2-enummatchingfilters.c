HRESULT EnumMatchingFilters(
  [out] IEnumMoniker       **ppEnum,
  [in]  DWORD              dwFlags,
  [in]  BOOL               bExactMatch,
  [in]  DWORD              dwMerit,
  [in]  BOOL               bInputNeeded,
  [in]  DWORD              cInputTypes,
  [in]  const GUID         *pInputTypes,
  [in]  const REGPINMEDIUM *pMedIn,
  [in]  const CLSID        *pPinCategoryIn,
  [in]  BOOL               bRender,
  [in]  BOOL               bOutputNeeded,
  [in]  DWORD              cOutputTypes,
  [in]  const GUID         *pOutputTypes,
  [in]  const REGPINMEDIUM *pMedOut,
  [in]  const CLSID        *pPinCategoryOut
);