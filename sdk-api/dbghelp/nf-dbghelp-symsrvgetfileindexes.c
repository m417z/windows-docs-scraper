BOOL IMAGEAPI SymSrvGetFileIndexes(
  [in]            PCSTR  File,
  [out]           GUID   *Id,
  [out]           PDWORD Val1,
  [out, optional] PDWORD Val2,
  [in]            DWORD  Flags
);