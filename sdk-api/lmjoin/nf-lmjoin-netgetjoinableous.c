NET_API_STATUS NET_API_FUNCTION NetGetJoinableOUs(
  [in]  LPCWSTR lpServer,
  [in]  LPCWSTR lpDomain,
  [in]  LPCWSTR lpAccount,
  [in]  LPCWSTR lpPassword,
  [out] DWORD   *OUCount,
  [out] LPWSTR  **OUs
);