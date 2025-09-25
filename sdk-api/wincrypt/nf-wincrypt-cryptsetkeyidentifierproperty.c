BOOL CryptSetKeyIdentifierProperty(
  [in]  const CRYPT_HASH_BLOB *pKeyIdentifier,
  [in]  DWORD                 dwPropId,
  [in]  DWORD                 dwFlags,
  [in]  LPCWSTR               pwszComputerName,
  [in]  void                  *pvReserved,
  [out] const void            *pvData
);