BOOL WTSEnumerateSessionsExW(
  [in]      HANDLE               hServer,
  [in, out] DWORD                *pLevel,
  [in]      DWORD                Filter,
  [out]     PWTS_SESSION_INFO_1W *ppSessionInfo,
  [out]     DWORD                *pCount
);