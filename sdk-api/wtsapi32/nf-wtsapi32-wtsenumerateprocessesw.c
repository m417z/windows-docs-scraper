BOOL WTSEnumerateProcessesW(
  [in]  HANDLE             hServer,
  [in]  DWORD              Reserved,
  [in]  DWORD              Version,
  [out] PWTS_PROCESS_INFOW *ppProcessInfo,
  [out] DWORD              *pCount
);