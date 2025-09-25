BOOL ReadEventLogW(
  [in]  HANDLE hEventLog,
  [in]  DWORD  dwReadFlags,
  [in]  DWORD  dwRecordOffset,
  [out] LPVOID lpBuffer,
  [in]  DWORD  nNumberOfBytesToRead,
  [out] DWORD  *pnBytesRead,
  [out] DWORD  *pnMinNumberOfBytesNeeded
);