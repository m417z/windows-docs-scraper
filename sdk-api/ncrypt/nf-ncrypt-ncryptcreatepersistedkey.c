SECURITY_STATUS NCryptCreatePersistedKey(
  [in]           NCRYPT_PROV_HANDLE hProvider,
  [out]          NCRYPT_KEY_HANDLE  *phKey,
  [in]           LPCWSTR            pszAlgId,
  [in, optional] LPCWSTR            pszKeyName,
  [in]           DWORD              dwLegacyKeySpec,
  [in]           DWORD              dwFlags
);