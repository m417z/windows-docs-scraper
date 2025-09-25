BOOL WTSEnumerateProcessesExW(
  [in]      HANDLE hServer,
  [in, out] DWORD  *pLevel,
  [in]      DWORD  SessionId,
  [out]     LPWSTR *ppProcessInfo,
  [out]     DWORD  *pCount
);