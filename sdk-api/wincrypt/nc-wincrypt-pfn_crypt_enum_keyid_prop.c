PFN_CRYPT_ENUM_KEYID_PROP PfnCryptEnumKeyidProp;

BOOL PfnCryptEnumKeyidProp(
  [in]      const CRYPT_HASH_BLOB *pKeyIdentifier,
  [in]      DWORD dwFlags,
  [in]      void *pvReserved,
  [in, out] void *pvArg,
  [in]      DWORD cProp,
  [in]      DWORD *rgdwPropId,
  [in]      void **rgpvData,
  [in]      DWORD *rgcbData
)
{...}