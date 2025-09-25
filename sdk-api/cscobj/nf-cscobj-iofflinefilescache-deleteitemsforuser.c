HRESULT DeleteItemsForUser(
  [in] LPCWSTR                     pszUser,
  [in] LPCWSTR                     *rgpszPaths,
  [in] ULONG                       cPaths,
  [in] DWORD                       dwFlags,
  [in] BOOL                        bAsync,
  [in] IOfflineFilesSimpleProgress *pIProgress
);