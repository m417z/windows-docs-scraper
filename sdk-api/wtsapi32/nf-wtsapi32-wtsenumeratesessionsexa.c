BOOL WTSEnumerateSessionsExA(
  [in]      HANDLE               hServer,
  [in, out] DWORD                *pLevel,
  [in]      DWORD                Filter,
  [out]     PWTS_SESSION_INFO_1A *ppSessionInfo,
  [out]     DWORD                *pCount
);