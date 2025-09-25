HRESULT GetManifestResourceProps(
  [in]  mdManifestResource mdmr,
  [out] LPWSTR             szName,
  [in]  ULONG              cchName,
  [out] ULONG              *pchName,
  [out] mdToken            *ptkImplementation,
  [out] DWORD              *pdwOffset,
  [out] DWORD              *pdwResourceFlags
);