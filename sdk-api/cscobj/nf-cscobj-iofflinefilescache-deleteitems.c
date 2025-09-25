HRESULT DeleteItems(
  [in] LPCWSTR                     *rgpszPaths,
  [in] ULONG                       cPaths,
  [in] DWORD                       dwFlags,
  [in] BOOL                        bAsync,
  [in] IOfflineFilesSimpleProgress *pIProgress
);