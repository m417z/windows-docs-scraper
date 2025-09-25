HRESULT StartXpsPrintJob(
  [in]  LPCWSTR            printerName,
  [in]  LPCWSTR            jobName,
  [in]  LPCWSTR            outputFileName,
  [in]  HANDLE             progressEvent,
  [in]  HANDLE             completionEvent,
  [in]  UINT8              *printablePagesOn,
  [in]  UINT32             printablePagesOnCount,
  [out] IXpsPrintJob       **xpsPrintJob,
  [out] IXpsPrintJobStream **documentStream,
  [out] IXpsPrintJobStream **printTicketStream
);