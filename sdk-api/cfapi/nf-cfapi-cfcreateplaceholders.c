HRESULT CfCreatePlaceholders(
  [in]      LPCWSTR                    BaseDirectoryPath,
  [in, out] CF_PLACEHOLDER_CREATE_INFO *PlaceholderArray,
  [in]      DWORD                      PlaceholderCount,
  [in]      CF_CREATE_FLAGS            CreateFlags,
  [out]     PDWORD                     EntriesProcessed
);