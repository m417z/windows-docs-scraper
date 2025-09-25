DWORD64 IMAGEAPI SymLoadModuleEx(
  [in] HANDLE        hProcess,
  [in] HANDLE        hFile,
  [in] PCSTR         ImageName,
  [in] PCSTR         ModuleName,
  [in] DWORD64       BaseOfDll,
  [in] DWORD         DllSize,
  [in] PMODLOAD_DATA Data,
  [in] DWORD         Flags
);