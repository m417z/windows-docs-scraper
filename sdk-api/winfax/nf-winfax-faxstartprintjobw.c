WINFAXAPI BOOL FaxStartPrintJobW(
  [in]  LPCWSTR               PrinterName,
  [in]  const FAX_PRINT_INFOW *PrintInfo,
  [out] LPDWORD               FaxJobId,
  [out] PFAX_CONTEXT_INFOW    FaxContextInfo
);