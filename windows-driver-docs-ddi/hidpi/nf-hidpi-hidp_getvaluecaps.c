NTSTATUS HidP_GetValueCaps(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [out]     PHIDP_VALUE_CAPS     ValueCaps,
  [in, out] PUSHORT              ValueCapsLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData
);