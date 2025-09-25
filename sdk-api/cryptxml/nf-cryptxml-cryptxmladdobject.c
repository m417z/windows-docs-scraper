HRESULT CryptXmlAddObject(
  [in]            HCRYPTXML                hSignatureOrObject,
                  DWORD                    dwFlags,
  [in, optional]  const CRYPT_XML_PROPERTY *rgProperty,
  [in]            ULONG                    cProperty,
  [in]            const CRYPT_XML_BLOB     *pEncoded,
  [out, optional] const CRYPT_XML_OBJECT   **ppObject
);