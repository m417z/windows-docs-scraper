PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE PfnCryptObjectLocatorProviderInitialize;

BOOL PfnCryptObjectLocatorProviderInitialize(
  [in]  PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH pfnFlush,
  [in]  LPVOID pContext,
  [out] DWORD *pdwExpectedObjectCount,
  [out] PCRYPT_OBJECT_LOCATOR_PROVIDER_TABLE *ppFuncTable,
  [out] void **ppPluginContext
)
{...}