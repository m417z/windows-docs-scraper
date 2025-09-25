PFN_CRYPT_XML_DATA_PROVIDER_READ PfnCryptXmlDataProviderRead;

HRESULT PfnCryptXmlDataProviderRead(
  [in, out] void *pvCallbackState,
  [out]     BYTE *pbData,
  [in]      ULONG cbData,
  [out]     ULONG *pcbRead
)
{...}