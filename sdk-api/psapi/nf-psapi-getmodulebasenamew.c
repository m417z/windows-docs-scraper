DWORD GetModuleBaseNameW(
  [in]           HANDLE  hProcess,
  [in, optional] HMODULE hModule,
  [out]          LPWSTR  lpBaseName,
  [in]           DWORD   nSize
);