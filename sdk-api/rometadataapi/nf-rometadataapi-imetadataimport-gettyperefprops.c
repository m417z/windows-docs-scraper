HRESULT GetTypeRefProps(
  [in]  mdTypeRef tkTypeRef,
  [out] mdToken   *ptkResolutionScope,
  [out] LPWSTR    szName,
  [in]  ULONG     cchName,
  [out] ULONG     *pchName
);