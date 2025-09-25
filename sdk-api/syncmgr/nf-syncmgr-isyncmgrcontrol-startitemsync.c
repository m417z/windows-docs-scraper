HRESULT StartItemSync(
  [in] LPCWSTR                    pszHandlerID,
  [in] LPCWSTR                    *ppszItemIDs,
  [in] ULONG                      cItems,
  [in] HWND                       hwndOwner,
  [in] IUnknown                   *punk,
  [in] SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags,
  [in] ISyncMgrSyncResult         *pResult
);