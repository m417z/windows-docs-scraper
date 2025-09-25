NTSTATUS HidP_SetUsageValue(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [in]      USAGE                Usage,
  [in]      ULONG                UsageValue,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in, out] PCHAR                Report,
  [in]      ULONG                ReportLength
);