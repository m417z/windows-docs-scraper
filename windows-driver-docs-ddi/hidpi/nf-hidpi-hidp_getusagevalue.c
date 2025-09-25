NTSTATUS HidP_GetUsageValue(
  [in]  HIDP_REPORT_TYPE     ReportType,
  [in]  USAGE                UsagePage,
  [in]  USHORT               LinkCollection,
  [in]  USAGE                Usage,
  [out] PULONG               UsageValue,
  [in]  PHIDP_PREPARSED_DATA PreparsedData,
  [in]  PCHAR                Report,
  [in]  ULONG                ReportLength
);