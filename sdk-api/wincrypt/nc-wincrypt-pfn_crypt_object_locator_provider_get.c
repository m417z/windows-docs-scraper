PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET PfnCryptObjectLocatorProviderGet;

BOOL PfnCryptObjectLocatorProviderGet(
  [in, optional] LPVOID pPluginContext,
  [in, optional] PCRYPT_DATA_BLOB pIdentifier,
  [in]           DWORD dwNameType,
  [in]           PCERT_NAME_BLOB pNameBlob,
  [out]          PBYTE *ppbContent,
  [out]          DWORD *pcbContent,
  [out]          PCWSTR *ppwszPassword,
  [out]          PCRYPT_DATA_BLOB *ppIdentifier
)
{...}