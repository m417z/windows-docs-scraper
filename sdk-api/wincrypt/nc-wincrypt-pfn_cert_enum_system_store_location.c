PFN_CERT_ENUM_SYSTEM_STORE_LOCATION PfnCertEnumSystemStoreLocation;

BOOL PfnCertEnumSystemStoreLocation(
  [in] LPCWSTR pwszStoreLocation,
  [in] DWORD dwFlags,
  [in] void *pvReserved,
  [in] void *pvArg
)
{...}