BOOL IMAGEAPI SymDeleteSymbolW(
  [in]           HANDLE  hProcess,
  [in]           ULONG64 BaseOfDll,
  [in, optional] PCWSTR  Name,
  [in]           DWORD64 Address,
  [in]           DWORD   Flags
);