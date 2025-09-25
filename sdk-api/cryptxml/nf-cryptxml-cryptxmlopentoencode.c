HRESULT CryptXmlOpenToEncode(
  [in, optional] const CRYPT_XML_TRANSFORM_CHAIN_CONFIG *pConfig,
                 DWORD                                  dwFlags,
  [in, optional] LPCWSTR                                wszId,
  [in]           const CRYPT_XML_PROPERTY               *rgProperty,
  [in]           ULONG                                  cProperty,
  [in, optional] const CRYPT_XML_BLOB                   *pEncoded,
  [optional]     HCRYPTXML                              *phSignature
);