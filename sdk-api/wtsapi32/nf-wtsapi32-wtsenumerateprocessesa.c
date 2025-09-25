BOOL WTSEnumerateProcessesA(
  [in]  HANDLE             hServer,
  [in]  DWORD              Reserved,
  [in]  DWORD              Version,
  [out] PWTS_PROCESS_INFOA *ppProcessInfo,
  [out] DWORD              *pCount
);