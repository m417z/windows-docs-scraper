BOOL BackupSeek(
  [in]  HANDLE  hFile,
  [in]  DWORD   dwLowBytesToSeek,
  [in]  DWORD   dwHighBytesToSeek,
  [out] LPDWORD lpdwLowByteSeeked,
  [out] LPDWORD lpdwHighByteSeeked,
  [in]  LPVOID  *lpContext
);