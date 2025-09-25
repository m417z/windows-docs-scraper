DWORD GetModuleFileNameExW(
  [in]           HANDLE  hProcess,
  [in, optional] HMODULE hModule,
  [out]          LPWSTR  lpFilename,
  [in]           DWORD   nSize
);