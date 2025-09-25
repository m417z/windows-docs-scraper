CryptXmlDllCreateDigest Cryptxmldllcreatedigest;

HRESULT Cryptxmldllcreatedigest(
  [in]  const CRYPT_XML_ALGORITHM *pDigestMethod,
  [out] ULONG *pcbSize,
  [out] CRYPT_XML_DIGEST *phDigest
)
{...}