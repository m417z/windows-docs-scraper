HRESULT FindItemEx(
  [in]  LPCWSTR                 pszPath,
  [in]  IOfflineFilesItemFilter *pIncludeFileFilter,
  [in]  IOfflineFilesItemFilter *pIncludeDirFilter,
  [in]  IOfflineFilesItemFilter *pExcludeFileFilter,
  [in]  IOfflineFilesItemFilter *pExcludeDirFilter,
  [in]  DWORD                   dwQueryFlags,
  [out] IOfflineFilesItem       **ppItem
);