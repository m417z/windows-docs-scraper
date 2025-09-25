SECURITY_STATUS NCryptOpenStorageProvider(
  [out]          NCRYPT_PROV_HANDLE *phProvider,
  [in, optional] LPCWSTR            pszProviderName,
  [in]           DWORD              dwFlags
);