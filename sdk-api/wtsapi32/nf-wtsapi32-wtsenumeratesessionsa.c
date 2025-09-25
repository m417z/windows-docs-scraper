BOOL WTSEnumerateSessionsA(
  [in]  HANDLE             hServer,
  [in]  DWORD              Reserved,
  [in]  DWORD              Version,
  [out] PWTS_SESSION_INFOA *ppSessionInfo,
  [out] DWORD              *pCount
);