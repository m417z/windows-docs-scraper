BOOL LookupPrivilegeNameA(
  [in, optional]  LPCSTR  lpSystemName,
  [in]            PLUID   lpLuid,
  [out, optional] LPSTR   lpName,
  [in, out]       LPDWORD cchName
);