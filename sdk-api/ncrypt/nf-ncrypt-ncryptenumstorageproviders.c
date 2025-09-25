SECURITY_STATUS NCryptEnumStorageProviders(
  [out] DWORD              *pdwProviderCount,
  [out] NCryptProviderName **ppProviderList,
  [in]  DWORD              dwFlags
);