BOOL IMAGEAPI SymQueryInlineTrace(
  [in]  HANDLE  hProcess,
  [in]  DWORD64 StartAddress,
  [in]  DWORD   StartContext,
  [in]  DWORD64 StartRetAddress,
  [in]  DWORD64 CurAddress,
  [out] LPDWORD CurContext,
  [out] LPDWORD CurFrameIndex
);