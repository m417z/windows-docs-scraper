DWORD InitiateShutdownW(
  [in, optional] LPWSTR lpMachineName,
  [in, optional] LPWSTR lpMessage,
  [in]           DWORD  dwGracePeriod,
  [in]           DWORD  dwShutdownFlags,
  [in]           DWORD  dwReason
);