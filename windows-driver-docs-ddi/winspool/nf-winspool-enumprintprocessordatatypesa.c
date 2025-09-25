BOOL EnumPrintProcessorDatatypesA(
  [in, optional]  LPSTR   pName,
  [in]            LPSTR   pPrintProcessorName,
                  DWORD   Level,
  [out, optional] LPBYTE  pDatatypes,
                  DWORD   cbBuf,
  [out]           LPDWORD pcbNeeded,
  [out]           LPDWORD pcReturned
);