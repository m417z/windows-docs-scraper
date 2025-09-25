HRESULT GetGenericParamProps(
  [in]  mdGenericParam gp,
  [out] ULONG          *pulParamSeq,
  [out] DWORD          *pdwParamFlags,
  [out] mdToken        *ptOwner,
  [out] DWORD          *reserved,
  [out] LPWSTR         wzname,
  [in]  ULONG          cchName,
  [out] ULONG          *pchName
);