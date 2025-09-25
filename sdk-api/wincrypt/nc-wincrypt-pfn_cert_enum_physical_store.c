PFN_CERT_ENUM_PHYSICAL_STORE PfnCertEnumPhysicalStore;

BOOL PfnCertEnumPhysicalStore(
  [in] const void *pvSystemStore,
  [in] DWORD dwFlags,
  [in] LPCWSTR pwszStoreName,
  [in] PCERT_PHYSICAL_STORE_INFO pStoreInfo,
  [in] void *pvReserved,
  [in] void *pvArg
)
{...}