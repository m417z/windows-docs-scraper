HRESULT CryptXmlCreateReference(
  [in]           HCRYPTXML                 hCryptXml,
                 DWORD                     dwFlags,
  [in, optional] LPCWSTR                   wszId,
  [in, optional] LPCWSTR                   wszURI,
  [in, optional] LPCWSTR                   wszType,
  [in]           const CRYPT_XML_ALGORITHM *pDigestMethod,
                 ULONG                     cTransform,
  [in]           const CRYPT_XML_ALGORITHM *rgTransform,
  [out]          HCRYPTXML                 *phReference
);