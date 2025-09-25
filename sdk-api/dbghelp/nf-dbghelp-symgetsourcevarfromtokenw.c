BOOL IMAGEAPI SymGetSourceVarFromTokenW(
  [in]           HANDLE hProcess,
  [in]           PVOID  Token,
  [in, optional] PCWSTR Params,
  [in]           PCWSTR VarName,
  [out]          PWSTR  Value,
  [in]           DWORD  Size
);