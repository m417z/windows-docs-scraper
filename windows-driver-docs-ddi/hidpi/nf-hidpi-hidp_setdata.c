NTSTATUS HidP_SetData(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in, out] PHIDP_DATA           DataList,
  [in, out] PULONG               DataLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in]      PCHAR                Report,
  [in]      ULONG                ReportLength
);