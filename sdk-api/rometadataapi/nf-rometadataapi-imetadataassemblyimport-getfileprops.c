HRESULT GetFileProps(
  [in]  mdFile     mdf,
  [out] LPWSTR     szName,
  [in]  ULONG      cchName,
  [out] ULONG      *pchName,
  [out] const BYTE **ppbHashValue,
  [out] ULONG      *pcbHashValue,
  [out] DWORD      *pdwFileFlags
);