WINSETUPAPI UINT SetupBackupErrorW(
  [in]  HWND   hwndParent,
  [in]  PCWSTR DialogTitle,
  [in]  PCWSTR SourceFile,
  [in]  PCWSTR TargetFile,
  [out] UINT   Win32ErrorCode,
  [in]  DWORD  Style
);