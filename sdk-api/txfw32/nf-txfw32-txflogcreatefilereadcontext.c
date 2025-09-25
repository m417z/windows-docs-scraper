BOOL TxfLogCreateFileReadContext(
  [in]  LPCWSTR  LogPath,
  [in]  CLFS_LSN BeginningLsn,
  [in]  CLFS_LSN EndingLsn,
  [in]  PTXF_ID  TxfFileId,
  [out] PVOID    *TxfLogContext
);