BOOL LookupPrivilegeDisplayNameA(
  [in, optional]  LPCSTR  lpSystemName,
  [in]            LPCSTR  lpName,
  [out, optional] LPSTR   lpDisplayName,
  [in, out]       LPDWORD cchDisplayName,
  [out]           LPDWORD lpLanguageId
);