WINSETUPAPI UINT SetupPromptForDiskW(
  [in]      HWND   hwndParent,
  [in]      PCWSTR DialogTitle,
  [in]      PCWSTR DiskName,
  [in]      PCWSTR PathToSource,
  [in]      PCWSTR FileSought,
  [in]      PCWSTR TagFile,
  [in]      DWORD  DiskPromptStyle,
  [in, out] PWSTR  PathBuffer,
  [in]      DWORD  PathBufferSize,
  [in, out] PDWORD PathRequiredSize
);