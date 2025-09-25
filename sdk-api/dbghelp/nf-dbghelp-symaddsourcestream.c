BOOL IMAGEAPI SymAddSourceStream(
  [in]           HANDLE  hProcess,
  [in]           ULONG64 Base,
  [in, optional] PCSTR   StreamFile,
  [in, optional] PBYTE   Buffer,
  [in]           size_t  Size
);