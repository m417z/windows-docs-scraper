NTSTATUS HidP_GetSpecificValueCaps(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [in]      USAGE                Usage,
  [out]     PHIDP_VALUE_CAPS     ValueCaps,
  [in, out] PUSHORT              ValueCapsLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData
);