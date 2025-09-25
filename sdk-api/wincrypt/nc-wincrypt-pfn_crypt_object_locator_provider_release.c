PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE PfnCryptObjectLocatorProviderRelease;

void PfnCryptObjectLocatorProviderRelease(
  [in]           DWORD dwReason,
  [in, optional] LPVOID pPluginContext
)
{...}