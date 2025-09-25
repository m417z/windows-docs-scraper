BOOL CopyFileExW(
  [in]           LPCWSTR            lpExistingFileName,
  [in]           LPCWSTR            lpNewFileName,
  [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
  [in, optional] LPVOID             lpData,
  [in, optional] LPBOOL             pbCancel,
  [in]           DWORD              dwCopyFlags
);