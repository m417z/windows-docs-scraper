HRESULT GenerateReport(
  [in]           GPMReportType gpmReportType,
  [in, optional] VARIANT       *pvarGPMProgress,
  [in, optional] VARIANT       *pvarGPMCancel,
  [out]          IGPMResult    **ppIGPMResult
);