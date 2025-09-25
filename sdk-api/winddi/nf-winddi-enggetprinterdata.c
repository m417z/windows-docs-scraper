ENGAPI DWORD EngGetPrinterData(
  [in]            HANDLE  hPrinter,
  [in]            LPWSTR  pValueName,
  [out, optional] LPDWORD pType,
  [out, optional] LPBYTE  pData,
  [in]            DWORD   nSize,
  [out]           LPDWORD pcbNeeded
);