HRESULT EnumItemsEx(
  [in]  IOfflineFilesItemFilter *pIncludeFileFilter,
  [in]  IOfflineFilesItemFilter *pIncludeDirFilter,
  [in]  IOfflineFilesItemFilter *pExcludeFileFilter,
  [in]  IOfflineFilesItemFilter *pExcludeDirFilter,
  [in]  DWORD                   dwEnumFlags,
  [in]  DWORD                   dwQueryFlags,
  [out] IEnumOfflineFilesItems  **ppenum
);