HRESULT StartHandlerSync(
  [in] LPCWSTR                    pszHandlerID,
  [in] HWND                       hwndOwner,
  [in] IUnknown                   *punk,
  [in] SYNCMGR_SYNC_CONTROL_FLAGS nSyncControlFlags,
  [in] ISyncMgrSyncResult         *pResult
);