BOOL BackupRead(
  [in]  HANDLE  hFile,
  [out] LPBYTE  lpBuffer,
  [in]  DWORD   nNumberOfBytesToRead,
  [out] LPDWORD lpNumberOfBytesRead,
  [in]  BOOL    bAbort,
  [in]  BOOL    bProcessSecurity,
  [out] LPVOID  *lpContext
);