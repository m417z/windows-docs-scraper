BOOL IMAGEAPI SymGetSourceFileToken(
  [in]  HANDLE  hProcess,
  [in]  ULONG64 Base,
  [in]  PCSTR   FileSpec,
  [out] PVOID   *Token,
  [out] DWORD   *Size
);