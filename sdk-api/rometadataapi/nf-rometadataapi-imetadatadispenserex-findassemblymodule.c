HRESULT FindAssemblyModule(
  [in]  LPCWSTR szAppBase,
  [in]  LPCWSTR szPrivateBin,
  [in]  LPCWSTR szGlobalBin,
  [in]  LPCWSTR szAssemblyName,
  [in]  LPCWSTR szModuleName,
  [out] LPWSTR  szName,
  [in]  ULONG   cchName,
  [out] ULONG   *pcName
);