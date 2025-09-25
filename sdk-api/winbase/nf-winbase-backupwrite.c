BOOL BackupWrite(
  [in]  HANDLE  hFile,
  [in]  LPBYTE  lpBuffer,
  [in]  DWORD   nNumberOfBytesToWrite,
  [out] LPDWORD lpNumberOfBytesWritten,
  [in]  BOOL    bAbort,
  [in]  BOOL    bProcessSecurity,
  [out] LPVOID  *lpContext
);