LONG ClusterRegCreateKey(
  [in]            HKEY                  hKey,
  [in]            LPCWSTR               lpszSubKey,
  [in]            DWORD                 dwOptions,
  [in]            REGSAM                samDesired,
  [in, optional]  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [out]           PHKEY                 phkResult,
  [out, optional] LPDWORD               lpdwDisposition
);