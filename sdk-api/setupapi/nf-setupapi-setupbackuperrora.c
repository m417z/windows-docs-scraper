WINSETUPAPI UINT SetupBackupErrorA(
  [in]  HWND  hwndParent,
  [in]  PCSTR DialogTitle,
  [in]  PCSTR SourceFile,
  [in]  PCSTR TargetFile,
  [out] UINT  Win32ErrorCode,
  [in]  DWORD Style
);