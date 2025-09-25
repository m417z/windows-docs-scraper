BOOL IMAGEAPI SymAddSymbolW(
  [in] HANDLE  hProcess,
  [in] ULONG64 BaseOfDll,
  [in] PCWSTR  Name,
  [in] DWORD64 Address,
  [in] DWORD   Size,
  [in] DWORD   Flags
);