NTSTATUS HidP_GetData(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [out]     PHIDP_DATA           DataList,
  [in, out] PULONG               DataLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData,
  [in]      PCHAR                Report,
  [in]      ULONG                ReportLength
);