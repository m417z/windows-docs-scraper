BOOL CryptEnumProvidersW(
  [in]      DWORD  dwIndex,
  [in]      DWORD  *pdwReserved,
  [in]      DWORD  dwFlags,
  [out]     DWORD  *pdwProvType,
  [out]     LPWSTR szProvName,
  [in, out] DWORD  *pcbProvName
);