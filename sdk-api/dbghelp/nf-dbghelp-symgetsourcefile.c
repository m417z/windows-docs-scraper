BOOL IMAGEAPI SymGetSourceFile(
  [in]           HANDLE  hProcess,
  [in]           ULONG64 Base,
  [in, optional] PCSTR   Params,
  [in]           PCSTR   FileSpec,
  [out]          PSTR    FilePath,
  [in]           DWORD   Size
);