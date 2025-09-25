NTSTATUS HidP_GetButtonCaps(
  [in]      HIDP_REPORT_TYPE     ReportType,
  [out]     PHIDP_BUTTON_CAPS    ButtonCaps,
  [in, out] PUSHORT              ButtonCapsLength,
  [in]      PHIDP_PREPARSED_DATA PreparsedData
);