ENGAPI BOOL EngGetForm(
  [in]           HANDLE  hPrinter,
  [in]           LPWSTR  pFormName,
  [in]           DWORD   Level,
  [in, optional] LPBYTE  pForm,
  [in]           DWORD   cbBuf,
  [out]          LPDWORD pcbNeeded
);