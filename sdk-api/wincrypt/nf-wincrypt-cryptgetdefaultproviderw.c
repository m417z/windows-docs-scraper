BOOL CryptGetDefaultProviderW(
  [in]      DWORD  dwProvType,
  [in]      DWORD  *pdwReserved,
  [in]      DWORD  dwFlags,
  [out]     LPWSTR pszProvName,
  [in, out] DWORD  *pcbProvName
);