BOOL CryptEnumKeyIdentifierProperties(
  [in, optional] const CRYPT_HASH_BLOB     *pKeyIdentifier,
  [in]           DWORD                     dwPropId,
  [in]           DWORD                     dwFlags,
  [in, optional] LPCWSTR                   pwszComputerName,
  [in]           void                      *pvReserved,
  [in, optional] void                      *pvArg,
  [in]           PFN_CRYPT_ENUM_KEYID_PROP pfnEnum
);