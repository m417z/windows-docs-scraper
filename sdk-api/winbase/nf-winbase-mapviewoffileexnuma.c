LPVOID MapViewOfFileExNuma(
  [in]           HANDLE hFileMappingObject,
  [in]           DWORD  dwDesiredAccess,
  [in]           DWORD  dwFileOffsetHigh,
  [in]           DWORD  dwFileOffsetLow,
  [in]           SIZE_T dwNumberOfBytesToMap,
  [in, optional] LPVOID lpBaseAddress,
  [in]           DWORD  nndPreferred
);