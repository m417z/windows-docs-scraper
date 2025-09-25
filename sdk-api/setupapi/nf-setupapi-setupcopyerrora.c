WINSETUPAPI UINT SetupCopyErrorA(
  [in]      HWND   hwndParent,
  [in]      PCSTR  DialogTitle,
  [in]      PCSTR  DiskName,
  [in]      PCSTR  PathToSource,
  [in]      PCSTR  SourceFile,
  [in]      PCSTR  TargetPathFile,
  [out]     UINT   Win32ErrorCode,
  [in]      DWORD  Style,
  [in, out] PSTR   PathBuffer,
  [in]      DWORD  PathBufferSize,
  [in, out] PDWORD PathRequiredSize
);