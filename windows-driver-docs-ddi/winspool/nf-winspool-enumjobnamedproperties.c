DWORD EnumJobNamedProperties(
  [in]  HANDLE             hPrinter,
  [in]  DWORD              JobId,
  [out] DWORD              *pcProperties,
  [out] PrintNamedProperty **ppProperties
);