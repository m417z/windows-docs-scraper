NTSTATUS HidP_GetSpecificButtonCaps(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [in]      USAGE                UsagePage,
  [in]      USHORT               LinkCollection,
  [in]      USAGE                Usage,
  [out]     PHIDP_BUTTON_CAPS    ButtonCaps,
  [in, out] PUSHORT              ButtonCapsLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData
);