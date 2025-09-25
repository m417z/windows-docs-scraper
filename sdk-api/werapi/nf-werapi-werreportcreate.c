HRESULT WerReportCreate(
  [in]           PCWSTR                  pwzEventType,
  [in]           WER_REPORT_TYPE         repType,
  [in, optional] PWER_REPORT_INFORMATION pReportInformation,
  [out]          HREPORT                 *phReportHandle
);