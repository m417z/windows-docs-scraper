BOOL IMAGEAPI SymAddSymbol(
  [in] HANDLE  hProcess,
  [in] ULONG64 BaseOfDll,
  [in] PCSTR   Name,
  [in] DWORD64 Address,
  [in] DWORD   Size,
  [in] DWORD   Flags
);