DWORD SetFilePointer(
  [in]                HANDLE hFile,
  [in]                LONG   lDistanceToMove,
  [in, out, optional] PLONG  lpDistanceToMoveHigh,
  [in]                DWORD  dwMoveMethod
);