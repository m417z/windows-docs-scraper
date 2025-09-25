NTSTATUS HidP_GetUsageValueArray(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [in]      USAGE                Usage,
  [in, out] PCHAR                UsageValue,
  [in]      USHORT               UsageValueByteLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in]      PCHAR                Report,
  [in]      ULONG                ReportLength
);