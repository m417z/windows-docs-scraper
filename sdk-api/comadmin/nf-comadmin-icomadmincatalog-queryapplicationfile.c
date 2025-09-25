HRESULT QueryApplicationFile(
  [in]  BSTR         bstrApplicationFile,
  [out] BSTR         *pbstrApplicationName,
  [out] BSTR         *pbstrApplicationDescription,
  [out] VARIANT_BOOL *pbHasUsers,
  [out] VARIANT_BOOL *pbIsProxy,
  [out] SAFEARRAY    **ppsaVarFileNames
);