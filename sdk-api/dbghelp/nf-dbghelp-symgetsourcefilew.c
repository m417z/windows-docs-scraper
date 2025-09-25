BOOL IMAGEAPI SymGetSourceFileW(
  [in]           HANDLE  hProcess,
  [in]           ULONG64 Base,
  [in, optional] PCWSTR  Params,
  [in]           PCWSTR  FileSpec,
  [out]          PWSTR   FilePath,
  [in]           DWORD   Size
);