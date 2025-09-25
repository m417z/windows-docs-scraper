HRESULT LoadIFilter(
  [in]      LPCWSTR               pwcsPath,
  [in]      FILTERED_DATA_SOURCES *pFilteredSources,
  [in]      IUnknown              *pUnkOuter,
  [in]      BOOL                  fUseDefault,
  [in, out] CLSID                 *pFilterClsid,
  [in, out] int                   *SearchDecSize,
  [in, out] WCHAR                 **pwcsSearchDesc,
  [in, out] IFilter               **ppIFilt
);