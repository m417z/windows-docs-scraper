CryptXmlDllCreateKey Cryptxmldllcreatekey;

HRESULT Cryptxmldllcreatekey(
  [in]  const CRYPT_XML_BLOB *pEncoded,
  [out] BCRYPT_KEY_HANDLE *phKey
)
{...}