HRESULT RegisterFilter(
  [in]      REFCLSID         clsidFilter,
  [in]      LPCWSTR          Name,
  [in, out] IMoniker         **ppMoniker,
  [in]      const CLSID      *pclsidCategory,
  [in]      LPCOLESTR        szInstance,
  [in]      const REGFILTER2 *prf2
);