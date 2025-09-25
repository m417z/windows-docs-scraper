HRESULT ResolveConflict(
  [in]  LPCWSTR                            pszPath,
  [in]  DWORD                              fStateKnown,
  [in]  OFFLINEFILES_SYNC_STATE            state,
  [in]  DWORD                              fChangeDetails,
  [out] OFFLINEFILES_SYNC_CONFLICT_RESOLVE *pConflictResolution,
  [out] LPWSTR                             *ppszNewName
);