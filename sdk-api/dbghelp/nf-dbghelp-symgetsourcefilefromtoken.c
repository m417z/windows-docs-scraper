BOOL IMAGEAPI SymGetSourceFileFromToken(
  [in]           HANDLE hProcess,
  [in]           PVOID  Token,
  [in, optional] PCSTR  Params,
  [out]          PSTR   FilePath,
  [in]           DWORD  Size
);