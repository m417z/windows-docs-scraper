BOOL WTSEnumerateServersA(
  [in] LPSTR             pDomainName,
  [in] DWORD             Reserved,
  [in] DWORD             Version,
       PWTS_SERVER_INFOA *ppServerInfo,
       DWORD             *pCount
);