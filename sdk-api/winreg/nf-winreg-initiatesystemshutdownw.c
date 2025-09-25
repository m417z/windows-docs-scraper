BOOL InitiateSystemShutdownW(
  [in, optional] LPWSTR lpMachineName,
  [in, optional] LPWSTR lpMessage,
  [in]           DWORD  dwTimeout,
  [in]           BOOL   bForceAppsClosed,
  [in]           BOOL   bRebootAfterShutdown
);