BOOL TxfLogCreateRangeReadContext(
  LPCWSTR        LogPath,
  CLFS_LSN       BeginningLsn,
  CLFS_LSN       EndingLsn,
  PLARGE_INTEGER BeginningVirtualClock,
  PLARGE_INTEGER EndingVirtualClock,
  ULONG          RecordTypeMask,
  PVOID          *TxfLogContext
);