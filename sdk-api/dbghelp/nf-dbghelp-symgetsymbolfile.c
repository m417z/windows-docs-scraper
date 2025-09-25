BOOL IMAGEAPI SymGetSymbolFile(
  [in, optional] HANDLE hProcess,
  [in, optional] PCSTR  SymPath,
  [in]           PCSTR  ImageFile,
  [in]           DWORD  Type,
  [out]          PSTR   SymbolFile,
  [in]           size_t cSymbolFile,
  [out]          PSTR   DbgFile,
  [in]           size_t cDbgFile
);