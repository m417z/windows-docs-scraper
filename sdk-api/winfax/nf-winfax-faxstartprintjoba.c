WINFAXAPI BOOL FaxStartPrintJobA(
  [in]  LPCSTR                PrinterName,
  [in]  const FAX_PRINT_INFOA *PrintInfo,
  [out] LPDWORD               FaxJobId,
  [out] PFAX_CONTEXT_INFOA    FaxContextInfo
);