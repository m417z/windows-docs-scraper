CryptXmlDllEncodeKeyValue Cryptxmldllencodekeyvalue;

HRESULT Cryptxmldllencodekeyvalue(
  [in]      NCRYPT_KEY_HANDLE hKey,
            CRYPT_XML_CHARSET dwCharset,
  [in, out] void *pvCallbackState,
  [in]      PFN_CRYPT_XML_WRITE_CALLBACK pfnWrite
)
{...}