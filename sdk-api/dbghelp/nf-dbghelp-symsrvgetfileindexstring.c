BOOL IMAGEAPI SymSrvGetFileIndexString(
  [in]           HANDLE hProcess,
  [in, optional] PCSTR  SrvPath,
  [in]           PCSTR  File,
  [out]          PSTR   Index,
  [in]           size_t Size,
  [in]           DWORD  Flags
);