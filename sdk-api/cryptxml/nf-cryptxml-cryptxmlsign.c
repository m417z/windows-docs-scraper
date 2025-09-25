HRESULT CryptXmlSign(
  [in]           HCRYPTXML                       hSignature,
  [in, optional] HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hKey,
                 DWORD                           dwKeySpec,
                 DWORD                           dwFlags,
                 CRYPT_XML_KEYINFO_SPEC          dwKeyInfoSpec,
  [in, optional] const void                      *pvKeyInfoSpec,
  [in]           const CRYPT_XML_ALGORITHM       *pSignatureMethod,
  [in]           const CRYPT_XML_ALGORITHM       *pCanonicalization
);