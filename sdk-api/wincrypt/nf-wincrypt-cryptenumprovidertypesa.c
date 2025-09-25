BOOL CryptEnumProviderTypesA(
  [in]      DWORD dwIndex,
  [in]      DWORD *pdwReserved,
  [in]      DWORD dwFlags,
  [out]     DWORD *pdwProvType,
  [out]     LPSTR szTypeName,
  [in, out] DWORD *pcbTypeName
);