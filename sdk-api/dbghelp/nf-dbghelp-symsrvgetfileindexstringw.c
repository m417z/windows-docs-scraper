BOOL IMAGEAPI SymSrvGetFileIndexStringW(
  [in]           HANDLE hProcess,
  [in, optional] PCWSTR SrvPath,
  [in]           PCWSTR File,
  [out]          PWSTR  Index,
  [in]           size_t Size,
  [in]           DWORD  Flags
);