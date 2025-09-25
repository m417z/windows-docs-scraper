HRESULT CreateItem(
  [in]  LPCWSTR               pszName,
  [in]  DWORD                 dwAttributes,
  [in]  ULONGLONG             ullSize,
  [in]  TRANSFER_SOURCE_FLAGS flags,
  [out] REFIID                riidItem,
  [out] void                  **ppvItem,
  [in]  REFIID                riidResources,
  [out] void                  **ppvResources
);