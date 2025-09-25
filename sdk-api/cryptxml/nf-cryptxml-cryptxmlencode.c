HRESULT CryptXmlEncode(
  [in]      HCRYPTXML                    hCryptXml,
            CRYPT_XML_CHARSET            dwCharset,
  [in]      const CRYPT_XML_PROPERTY     *rgProperty,
  [in]      ULONG                        cProperty,
  [in, out] void                         *pvCallbackState,
  [in]      PFN_CRYPT_XML_WRITE_CALLBACK pfnWrite
);