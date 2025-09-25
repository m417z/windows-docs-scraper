DWORD64 IMAGEAPI SymLoadModule64(
  [in]           HANDLE  hProcess,
  [in, optional] HANDLE  hFile,
  [in, optional] PCSTR   ImageName,
  [in, optional] PCSTR   ModuleName,
  [in]           DWORD64 BaseOfDll,
  [in]           DWORD   SizeOfDll
);