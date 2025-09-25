BOOL LookupPrivilegeDisplayNameW(
  [in, optional]  LPCWSTR lpSystemName,
  [in]            LPCWSTR lpName,
  [out, optional] LPWSTR  lpDisplayName,
  [in, out]       LPDWORD cchDisplayName,
  [out]           LPDWORD lpLanguageId
);