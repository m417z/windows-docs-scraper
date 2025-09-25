NTSTATUS HidP_GetButtonArray(
  HIDP_REPORT_TYPE        ReportType,
  USAGE                   UsagePage,
  USHORT                  LinkCollection,
  USAGE                   Usage,
  PHIDP_BUTTON_ARRAY_DATA ButtonData,
  PUSHORT                 ButtonDataLength,
  PHIDP_PREPARSED_DATA    PreparsedData,
  PCHAR                   Report,
  ULONG                   ReportLength
);