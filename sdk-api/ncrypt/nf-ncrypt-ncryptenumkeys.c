SECURITY_STATUS NCryptEnumKeys(
  [in]           NCRYPT_PROV_HANDLE hProvider,
  [in, optional] LPCWSTR            pszScope,
  [out]          NCryptKeyName      **ppKeyName,
  [in, out]      PVOID              *ppEnumState,
  [in]           DWORD              dwFlags
);