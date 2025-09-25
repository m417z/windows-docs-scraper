HRESULT GetExportedTypeProps(
  [in]  mdExportedType mdct,
  [out] LPWSTR         szName,
  [in]  ULONG          cchName,
  [out] ULONG          *pchName,
  [out] mdToken        *ptkImplementation,
  [out] mdTypeDef      *ptkTypeDef,
  [out] DWORD          *pdwExportedTypeFlags
);