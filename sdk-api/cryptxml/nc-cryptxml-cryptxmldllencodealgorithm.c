CryptXmlDllEncodeAlgorithm Cryptxmldllencodealgorithm;

HRESULT Cryptxmldllencodealgorithm(
  [in]      const CRYPT_XML_ALGORITHM_INFO *pAlgInfo,
            CRYPT_XML_CHARSET dwCharset,
  [in, out] void *pvCallbackState,
  [in]      PFN_CRYPT_XML_WRITE_CALLBACK pfnWrite
)
{...}