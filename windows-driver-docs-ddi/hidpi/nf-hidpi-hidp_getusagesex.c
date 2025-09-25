NTSTATUS HidP_GetUsagesEx(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USHORT               LinkCollection,
  [in, out] PUSAGE_AND_PAGE      ButtonList,
  [in, out] ULONG                *UsageLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in]      PCHAR                Report,
  [in]      ULONG                ReportLength
);