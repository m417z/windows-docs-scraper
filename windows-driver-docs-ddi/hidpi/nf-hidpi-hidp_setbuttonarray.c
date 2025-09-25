NTSTATUS HidP_SetButtonArray(
  HIDP_REPORT_TYPE        ReportType,
  USAGE                   UsagePage,
  USHORT                  LinkCollection,
  USAGE                   Usage,
  PHIDP_BUTTON_ARRAY_DATA ButtonData,
  USHORT                  ButtonDataLength,
  PHIDP_PREPARSED_DATA    PreparsedData,
  PCHAR                   Report,
  ULONG                   ReportLength
);