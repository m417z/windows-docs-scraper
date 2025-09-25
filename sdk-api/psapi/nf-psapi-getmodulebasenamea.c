DWORD GetModuleBaseNameA(
  [in]           HANDLE  hProcess,
  [in, optional] HMODULE hModule,
  [out]          LPSTR   lpBaseName,
  [in]           DWORD   nSize
);