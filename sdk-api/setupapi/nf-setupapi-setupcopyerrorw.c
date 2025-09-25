WINSETUPAPI UINT SetupCopyErrorW(
  [in]      HWND   hwndParent,
  [in]      PCWSTR DialogTitle,
  [in]      PCWSTR DiskName,
  [in]      PCWSTR PathToSource,
  [in]      PCWSTR SourceFile,
  [in]      PCWSTR TargetPathFile,
  [out]     UINT   Win32ErrorCode,
  [in]      DWORD  Style,
  [in, out] PWSTR  PathBuffer,
  [in]      DWORD  PathBufferSize,
  [in, out] PDWORD PathRequiredSize
);