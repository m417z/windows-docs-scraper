HRESULT GenerateReport(
  [in]            GPMReportType gpmReportType,
  [in, optional]  VARIANT       *pvarGPMProgress,
  [out, optional] VARIANT       *pvarGPMCancel,
  [out]           IGPMResult    **ppIGPMResult
);