DWORD IMAGEAPI SymLoadModule(
  [in]           HANDLE hProcess,
  [in, optional] HANDLE hFile,
  [in, optional] PCSTR  ImageName,
  [in, optional] PCSTR  ModuleName,
  [in]           DWORD  BaseOfDll,
  [in]           DWORD  SizeOfDll
);