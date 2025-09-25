BOOL IMAGEAPI SymDeleteSymbol(
  [in]           HANDLE  hProcess,
  [in]           ULONG64 BaseOfDll,
  [in, optional] PCSTR   Name,
  [in]           DWORD64 Address,
  [in]           DWORD   Flags
);