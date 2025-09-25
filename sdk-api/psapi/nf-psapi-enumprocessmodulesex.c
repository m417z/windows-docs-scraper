BOOL EnumProcessModulesEx(
  [in]  HANDLE  hProcess,
  [out] HMODULE *lphModule,
  [in]  DWORD   cb,
  [out] LPDWORD lpcbNeeded,
  [in]  DWORD   dwFilterFlag
);