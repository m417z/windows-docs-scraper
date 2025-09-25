BOOL WTSEnumerateServersW(
  [in] LPWSTR            pDomainName,
  [in] DWORD             Reserved,
  [in] DWORD             Version,
       PWTS_SERVER_INFOW *ppServerInfo,
       DWORD             *pCount
);