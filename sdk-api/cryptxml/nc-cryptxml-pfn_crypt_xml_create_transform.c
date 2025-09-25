PFN_CRYPT_XML_CREATE_TRANSFORM PfnCryptXmlCreateTransform;

HRESULT PfnCryptXmlCreateTransform(
  [in]  const CRYPT_XML_ALGORITHM *pTransform,
  [in]  CRYPT_XML_DATA_PROVIDER *pProviderIn,
  [out] CRYPT_XML_DATA_PROVIDER *pProviderOut
)
{...}