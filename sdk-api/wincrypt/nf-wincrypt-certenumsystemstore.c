BOOL CertEnumSystemStore(
  [in]           DWORD                      dwFlags,
  [in, optional] void                       *pvSystemStoreLocationPara,
  [in]           void                       *pvArg,
  [in]           PFN_CERT_ENUM_SYSTEM_STORE pfnEnum
);