BOOL MoveFileWithProgressA(
  [in]           LPCSTR             lpExistingFileName,
  [in, optional] LPCSTR             lpNewFileName,
  [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
  [in, optional] LPVOID             lpData,
  [in]           DWORD              dwFlags
);