BOOL IMAGEAPI SymGetSourceFileTokenW(
  [in]  HANDLE  hProcess,
  [in]  ULONG64 Base,
  [in]  PCWSTR  FileSpec,
  [out] PVOID   *Token,
  [out] DWORD   *Size
);