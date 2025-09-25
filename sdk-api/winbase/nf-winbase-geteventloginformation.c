BOOL GetEventLogInformation(
  [in]  HANDLE  hEventLog,
  [in]  DWORD   dwInfoLevel,
  [out] LPVOID  lpBuffer,
  [in]  DWORD   cbBufSize,
  [out] LPDWORD pcbBytesNeeded
);