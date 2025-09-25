DWORD InitiateShutdownA(
  [in, optional] LPSTR lpMachineName,
  [in, optional] LPSTR lpMessage,
  [in]           DWORD dwGracePeriod,
  [in]           DWORD dwShutdownFlags,
  [in]           DWORD dwReason
);