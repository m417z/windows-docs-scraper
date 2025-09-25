BOOL WTSEnumerateProcessesExA(
  [in]      HANDLE hServer,
  [in, out] DWORD  *pLevel,
  [in]      DWORD  SessionId,
  [out]     LPSTR  *ppProcessInfo,
  [out]     DWORD  *pCount
);