NTSTATUS HidP_SetScaledUsageValue(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [in]      USAGE                Usage,
  [in]      LONG                 UsageValue,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in, out] PCHAR                Report,
  [in]      ULONG                ReportLength
);