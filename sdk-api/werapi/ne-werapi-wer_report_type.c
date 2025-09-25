typedef enum _WER_REPORT_TYPE {
  WerReportNonCritical,
  WerReportCritical,
  WerReportApplicationCrash,
  WerReportApplicationHang,
  WerReportKernel,
  WerReportInvalid
} WER_REPORT_TYPE;