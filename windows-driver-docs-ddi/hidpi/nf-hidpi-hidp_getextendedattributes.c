NTSTATUS HidP_GetExtendedAttributes(
  [in]      HIDP_REPORT_TYPE          ReportType,
  [in]      USHORT                    DataIndex,
  [in]      PHIDP_PREPARSED_DATA      PreparsedData,
  [out]     PHIDP_EXTENDED_ATTRIBUTES Attributes,
  [in, out] PULONG                    LengthAttributes
);