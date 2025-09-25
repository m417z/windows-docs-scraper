BOOL IMAGEAPI SymGetSourceFileFromTokenW(
  [in]           HANDLE hProcess,
  [in]           PVOID  Token,
  [in, optional] PCWSTR Params,
  [out]          PWSTR  FilePath,
  [in]           DWORD  Size
);