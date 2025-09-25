BOOL WTSQueryUserConfigA(
  [in]  LPSTR            pServerName,
  [in]  LPSTR            pUserName,
  [in]  WTS_CONFIG_CLASS WTSConfigClass,
  [out] LPSTR            *ppBuffer,
  [out] DWORD            *pBytesReturned
);