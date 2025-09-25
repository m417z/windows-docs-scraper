PFN_CRYPT_XML_WRITE_CALLBACK PfnCryptXmlWriteCallback;

HRESULT PfnCryptXmlWriteCallback(
  [in, out] void *pvCallbackState,
  [in]      const BYTE *pbData,
            ULONG cbData
)
{...}