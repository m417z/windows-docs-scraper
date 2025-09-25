NTSTATUS HidP_GetScaledUsageValue(
  [in]  HIDP_REPORT_TYPE     ReportType,
  [in]  USAGE                UsagePage,
  [in]  USHORT               LinkCollection,
  [in]  USAGE                Usage,
  [out] PLONG                UsageValue,
  [in]  PHIDP_PREPARSED_DATA PreparsedData,
  [in]  PCHAR                Report,
  [in]  ULONG                ReportLength
);