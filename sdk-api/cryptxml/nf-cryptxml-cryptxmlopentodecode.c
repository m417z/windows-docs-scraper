HRESULT CryptXmlOpenToDecode(
  [in, optional] const CRYPT_XML_TRANSFORM_CHAIN_CONFIG *pConfig,
                 DWORD                                  dwFlags,
  [in]           const CRYPT_XML_PROPERTY               *rgProperty,
                 ULONG                                  cProperty,
  [in]           const CRYPT_XML_BLOB                   *pEncoded,
                 HCRYPTXML                              *phCryptXml
);