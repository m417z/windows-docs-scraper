HRESULT CreateStringLeaf(
  [in]  REFPROPERTYKEY             propkey,
  [in]  CONDITION_OPERATION        cop,
  [in]  LPCWSTR                    pszValue,
  [in]  LPCWSTR                    pszLocaleName,
  [in]  CONDITION_CREATION_OPTIONS cco,
  [in]  REFIID                     riid,
  [out] void                       **ppv
);