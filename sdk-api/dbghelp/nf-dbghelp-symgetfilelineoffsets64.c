ULONG IMAGEAPI SymGetFileLineOffsets64(
  [in]           HANDLE   hProcess,
  [in, optional] PCSTR    ModuleName,
  [in]           PCSTR    FileName,
  [out]          PDWORD64 Buffer,
  [in]           ULONG    BufferLines
);