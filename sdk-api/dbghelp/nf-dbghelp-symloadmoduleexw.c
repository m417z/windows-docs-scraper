DWORD64 IMAGEAPI SymLoadModuleExW(
  [in] HANDLE        hProcess,
  [in] HANDLE        hFile,
  [in] PCWSTR        ImageName,
  [in] PCWSTR        ModuleName,
  [in] DWORD64       BaseOfDll,
  [in] DWORD         DllSize,
  [in] PMODLOAD_DATA Data,
  [in] DWORD         Flags
);