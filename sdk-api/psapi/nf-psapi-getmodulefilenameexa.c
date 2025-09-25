DWORD GetModuleFileNameExA(
  [in]           HANDLE  hProcess,
  [in, optional] HMODULE hModule,
  [out]          LPSTR   lpFilename,
  [in]           DWORD   nSize
);