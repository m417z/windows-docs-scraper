BOOL WTSEnumerateSessionsW(
  [in]  HANDLE             hServer,
  [in]  DWORD              Reserved,
  [in]  DWORD              Version,
  [out] PWTS_SESSION_INFOW *ppSessionInfo,
  [out] DWORD              *pCount
);