BOOL SetFilePointerEx(
  [in]            HANDLE         hFile,
  [in]            LARGE_INTEGER  liDistanceToMove,
  [out, optional] PLARGE_INTEGER lpNewFilePointer,
  [in]            DWORD          dwMoveMethod
);