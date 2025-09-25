HRESULT Synchronize(
  [in] HWND                             hwndParent,
  [in] LPCWSTR                          *rgpszPaths,
  [in] ULONG                            cPaths,
  [in] BOOL                             bAsync,
  [in] DWORD                            dwSyncControl,
  [in] IOfflineFilesSyncConflictHandler *pISyncConflictHandler,
  [in] IOfflineFilesSyncProgress        *pIProgress,
  [in] GUID                             *pSyncId
);