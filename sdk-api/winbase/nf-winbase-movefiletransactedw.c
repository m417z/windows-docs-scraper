BOOL MoveFileTransactedW(
  [in]           LPCWSTR            lpExistingFileName,
  [in, optional] LPCWSTR            lpNewFileName,
  [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
  [in, optional] LPVOID             lpData,
  [in]           DWORD              dwFlags,
  [in]           HANDLE             hTransaction
);