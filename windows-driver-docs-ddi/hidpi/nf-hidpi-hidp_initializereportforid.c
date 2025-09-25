NTSTATUS HidP_InitializeReportForID(
  [in]  HIDP_REPORT_TYPE     ReportType,
  [in]  UCHAR                ReportID,
  [in]  PHIDP_PREPARSED_DATA PreparsedData,
  [out] PCHAR                Report,
  [in]  ULONG                ReportLength
);