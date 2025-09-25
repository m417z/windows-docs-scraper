BOOL IMAGEAPI SymGetSymbolFileW(
  [in, optional] HANDLE hProcess,
  [in, optional] PCWSTR SymPath,
  [in]           PCWSTR ImageFile,
  [in]           DWORD  Type,
  [out]          PWSTR  SymbolFile,
  [in]           size_t cSymbolFile,
  [out]          PWSTR  DbgFile,
  [in]           size_t cDbgFile
);