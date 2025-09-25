NTSTATUS HidP_GetUsages(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [out]     PUSAGE               UsageList,
  [in, out] PULONG               UsageLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [out]     PCHAR                Report,
  [in]      ULONG                ReportLength
);