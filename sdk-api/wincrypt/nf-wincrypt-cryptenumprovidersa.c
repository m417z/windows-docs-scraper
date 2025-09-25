BOOL CryptEnumProvidersA(
  [in]      DWORD dwIndex,
  [in]      DWORD *pdwReserved,
  [in]      DWORD dwFlags,
  [out]     DWORD *pdwProvType,
  [out]     LPSTR szProvName,
  [in, out] DWORD *pcbProvName
);