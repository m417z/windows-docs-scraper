BOOL CryptGetKeyIdentifierProperty(
  [in]      const CRYPT_HASH_BLOB *pKeyIdentifier,
  [in]      DWORD                 dwPropId,
  [in]      DWORD                 dwFlags,
  [in]      LPCWSTR               pwszComputerName,
  [in]      void                  *pvReserved,
  [out]     void                  *pvData,
  [in, out] DWORD                 *pcbData
);