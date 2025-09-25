NTSTATUS HidP_SetUsages(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [in, out] PUSAGE               UsageList,
  [in, out] PULONG               UsageLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in]      PCHAR                Report,
  [in]      ULONG                ReportLength
);