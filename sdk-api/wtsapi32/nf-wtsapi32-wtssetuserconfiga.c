BOOL WTSSetUserConfigA(
  [in] LPSTR            pServerName,
  [in] LPSTR            pUserName,
  [in] WTS_CONFIG_CLASS WTSConfigClass,
  [in] LPSTR            pBuffer,
  [in] DWORD            DataLength
);