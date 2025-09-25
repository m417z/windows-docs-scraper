HRESULT FindAssembly(
  [in]  LPCWSTR szAppBase,
  [in]  LPCWSTR szPrivateBin,
  [in]  LPCWSTR szGlobalBin,
  [in]  LPCWSTR szAssemblyName,
  [out] LPWSTR  szName,
  [in]  ULONG   cchName,
  [out] ULONG   *pchName
);