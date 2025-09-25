ENGAPI BOOL EngGetPrinter(
  [in]            HANDLE  hPrinter,
  [in]            DWORD   dwLevel,
  [out, optional] LPBYTE  pPrinter,
  [in]            DWORD   cbBuf,
  [out]           LPDWORD pcbNeeded
);