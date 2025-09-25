SECURITY_STATUS NCryptOpenKey(
  [in]  NCRYPT_PROV_HANDLE hProvider,
  [out] NCRYPT_KEY_HANDLE  *phKey,
  [in]  LPCWSTR            pszKeyName,
  [in]  DWORD              dwLegacyKeySpec,
  [in]  DWORD              dwFlags
);