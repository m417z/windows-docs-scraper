BOOL WTSQueryUserConfigW(
  [in]  LPWSTR           pServerName,
  [in]  LPWSTR           pUserName,
  [in]  WTS_CONFIG_CLASS WTSConfigClass,
  [out] LPWSTR           *ppBuffer,
  [out] DWORD            *pBytesReturned
);