HRESULT WINAPI GetKeyStorageInterface(
  _In_ LPCWSTR pszProviderName,
  _Out_ NCRYPT_KEY_STORAGE_FUNCTION_TABLE** ppFunctionTable,
  _In_ DWORD dwFlags
);