BOOL LookupPrivilegeNameW(
  [in, optional]  LPCWSTR lpSystemName,
  [in]            PLUID   lpLuid,
  [out, optional] LPWSTR  lpName,
  [in, out]       LPDWORD cchName
);