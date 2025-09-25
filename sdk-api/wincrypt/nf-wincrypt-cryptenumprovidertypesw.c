BOOL CryptEnumProviderTypesW(
  [in]      DWORD  dwIndex,
  [in]      DWORD  *pdwReserved,
  [in]      DWORD  dwFlags,
  [out]     DWORD  *pdwProvType,
  [out]     LPWSTR szTypeName,
  [in, out] DWORD  *pcbTypeName
);