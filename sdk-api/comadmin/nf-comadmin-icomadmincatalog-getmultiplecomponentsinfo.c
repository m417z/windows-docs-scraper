HRESULT GetMultipleComponentsInfo(
  [in]  BSTR      bstrApplIdOrName,
  [in]  SAFEARRAY **ppsaVarFileNames,
  [out] SAFEARRAY **ppsaVarCLSIDs,
  [out] SAFEARRAY **ppsaVarClassNames,
  [out] SAFEARRAY **ppsaVarFileFlags,
  [out] SAFEARRAY **ppsaVarComponentFlags
);