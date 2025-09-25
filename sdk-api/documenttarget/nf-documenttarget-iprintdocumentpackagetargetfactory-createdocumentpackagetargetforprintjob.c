HRESULT CreateDocumentPackageTargetForPrintJob(
  [in]  LPCWSTR                     printerName,
  [in]  LPCWSTR                     jobName,
  [in]  IStream                     *jobOutputStream,
  [in]  IStream                     *jobPrintTicketStream,
  [out] IPrintDocumentPackageTarget **docPackageTarget
);