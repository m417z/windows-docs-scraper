BOOL CryptGetDefaultProviderA(
  [in]      DWORD dwProvType,
  [in]      DWORD *pdwReserved,
  [in]      DWORD dwFlags,
  [out]     LPSTR pszProvName,
  [in, out] DWORD *pcbProvName
);