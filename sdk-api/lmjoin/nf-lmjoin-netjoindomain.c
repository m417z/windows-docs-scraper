NET_API_STATUS NET_API_FUNCTION NetJoinDomain(
  [in] LPCWSTR lpServer,
  [in] LPCWSTR lpDomain,
  [in] LPCWSTR lpMachineAccountOU,
  [in] LPCWSTR lpAccount,
  [in] LPCWSTR lpPassword,
  [in] DWORD   fJoinOptions
);