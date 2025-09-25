CryptXmlDllGetInterface Cryptxmldllgetinterface;

HRESULT Cryptxmldllgetinterface(
        DWORD dwFlags,
  [in]  const CRYPT_XML_ALGORITHM_INFO *pMethod,
  [out] CRYPT_XML_CRYPTOGRAPHIC_INTERFACE *pInterface
)
{...}