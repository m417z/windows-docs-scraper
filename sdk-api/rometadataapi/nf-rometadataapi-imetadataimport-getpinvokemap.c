HRESULT GetPinvokeMap(
  [in]  mdToken     tk,
  [out] DWORD       *pdwMappingFlags,
  [out] LPWSTR      szImportName,
  [in]  ULONG       cchImportName,
  [out] ULONG       *pchImportName,
  [out] mdModuleRef *ptkImportDLL
);