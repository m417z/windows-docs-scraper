BOOL WTSSetUserConfigW(
  [in] LPWSTR           pServerName,
  [in] LPWSTR           pUserName,
  [in] WTS_CONFIG_CLASS WTSConfigClass,
  [in] LPWSTR           pBuffer,
  [in] DWORD            DataLength
);