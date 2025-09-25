NTSTATUS HidP_SetUsageValueArray(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [in]      USAGE                Usage,
  [in]      PCHAR                UsageValue,
  [in]      USHORT               UsageValueByteLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in, out] PCHAR                Report,
  [in]      ULONG                ReportLength
);