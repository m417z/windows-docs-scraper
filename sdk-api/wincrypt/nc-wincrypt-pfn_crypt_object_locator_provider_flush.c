PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH PfnCryptObjectLocatorProviderFlush;

BOOL PfnCryptObjectLocatorProviderFlush(
  [in] LPVOID pContext,
  [in] PCERT_NAME_BLOB *rgIdentifierOrNameList,
  [in] DWORD dwIdentifierOrNameListCount
)
{...}