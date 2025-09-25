BOOL IMAGEAPI SymAddSourceStreamW(
  [in]           HANDLE  hProcess,
  [in]           ULONG64 Base,
                 PCWSTR  FileSpec,
  [in, optional] PBYTE   Buffer,
  [in]           size_t  Size
);