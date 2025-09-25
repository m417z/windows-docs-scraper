HRESULT LoadIFilterFromStorage(
  [in]      IStorage *pStg,
  [in]      IUnknown *pUnkOuter,
  [in]      LPCWSTR  pwcsOverride,
  [in]      BOOL     fUseDefault,
  [in, out] CLSID    *pFilterClsid,
  [in, out] int      *SearchDecSize,
  [in, out] WCHAR    **pwcsSearchDesc,
  [in, out] IFilter  **ppIFilt
);