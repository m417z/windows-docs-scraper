BOOL IMAGEAPI SymGetSourceVarFromToken(
  [in]           HANDLE hProcess,
  [in]           PVOID  Token,
  [in, optional] PCSTR  Params,
  [in]           PCSTR  VarName,
  [out]          PSTR   Value,
  [in]           DWORD  Size
);