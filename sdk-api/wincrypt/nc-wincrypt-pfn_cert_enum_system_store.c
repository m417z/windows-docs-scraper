PFN_CERT_ENUM_SYSTEM_STORE PfnCertEnumSystemStore;

BOOL PfnCertEnumSystemStore(
  [in] const void *pvSystemStore,
  [in] DWORD dwFlags,
  [in] PCERT_SYSTEM_STORE_INFO pStoreInfo,
  [in] void *pvReserved,
  [in] void *pvArg
)
{...}