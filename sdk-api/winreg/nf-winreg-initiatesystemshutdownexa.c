BOOL InitiateSystemShutdownExA(
  [in, optional] LPSTR lpMachineName,
  [in, optional] LPSTR lpMessage,
  [in]           DWORD dwTimeout,
  [in]           BOOL  bForceAppsClosed,
  [in]           BOOL  bRebootAfterShutdown,
  [in]           DWORD dwReason
);