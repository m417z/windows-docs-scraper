HRESULT GetParamProps(
  [in]  mdParamDef    tkParamDef,
  [out] mdMethodDef   *ptkMethodDef,
  [out] ULONG         *pulSequence,
  [out] LPWSTR        szName,
  [in]  ULONG         cchName,
  [out] ULONG         *pchName,
  [out] DWORD         *pdwAttr,
  [out] DWORD         *pdwCPlusTypeFlag,
  [out] UVCP_CONSTANT *ppValue,
  [out] ULONG         *pcchValue
);