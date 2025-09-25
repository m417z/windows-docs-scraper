WINSETUPAPI UINT SetupPromptForDiskA(
  [in]      HWND   hwndParent,
  [in]      PCSTR  DialogTitle,
  [in]      PCSTR  DiskName,
  [in]      PCSTR  PathToSource,
  [in]      PCSTR  FileSought,
  [in]      PCSTR  TagFile,
  [in]      DWORD  DiskPromptStyle,
  [in, out] PSTR   PathBuffer,
  [in]      DWORD  PathBufferSize,
  [in, out] PDWORD PathRequiredSize
);