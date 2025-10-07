HRESULT DsRestoreRegister(
  _In_ HBC        hbc,
  _In_ LPCTSTR    szCheckPointFilePath,
  _In_ LPCTSTR    szLogPath,
  _In_ EDB_RSTMAP rgrstmap[],
  _In_ LONG       crstmap,
  _In_ LPCTSTR    szBackupLogPath,
  _In_ ULONG      genLow,
  _In_ ULONG      genHigh
);