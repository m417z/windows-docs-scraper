BOOL IMAGEAPI SymSrvGetFileIndexesW(
  [in]            PCWSTR File,
  [out]           GUID   *Id,
  [out]           PDWORD Val1,
  [out, optional] PDWORD Val2,
  [in]            DWORD  Flags
);