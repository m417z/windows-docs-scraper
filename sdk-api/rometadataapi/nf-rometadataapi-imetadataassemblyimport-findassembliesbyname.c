HRESULT FindAssembliesByName(
  [in]  LPCWSTR       szAppBase,
  [in]  LPCWSTR       szPrivateBin,
  [in]  LPCWSTR       szAssemblyName,
  [out] IUnknown * [] ppIUnk,
  [in]  ULONG         cMax,
  [out] ULONG         *pcAssemblies
);