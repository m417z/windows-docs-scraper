HRESULT CfSetInSyncState(
  [in]                HANDLE               FileHandle,
  [in]                CF_IN_SYNC_STATE     InSyncState,
  [in]                CF_SET_IN_SYNC_FLAGS InSyncFlags,
  [in, out, optional] USN                  *InSyncUsn
);