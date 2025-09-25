PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER PfnCryptObjectLocatorProviderFreeIdentifier;

void PfnCryptObjectLocatorProviderFreeIdentifier(
  [in, optional] LPVOID pPluginContext,
  [in]           PCRYPT_DATA_BLOB pIdentifier
)
{...}