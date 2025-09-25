ENGAPI BOOL EngEnumForms(
  [in]            HANDLE  hPrinter,
  [in]            DWORD   Level,
  [out, optional] LPBYTE  pForm,
  [in]            DWORD   cbBuf,
  [out]           LPDWORD pcbNeeded,
  [out]           LPDWORD pcReturned
);