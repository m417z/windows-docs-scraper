typedef struct _PosDeviceInformation {
  wchar_t UnifiedPOSVersion[STATISTICS_STRING_SIZE];
  wchar_t DeviceCategory[STATISTICS_STRING_SIZE];
  wchar_t ManufacturerName[STATISTICS_STRING_SIZE];
  wchar_t ModelName[STATISTICS_STRING_SIZE];
  wchar_t SerialNumber[STATISTICS_STRING_SIZE];
  wchar_t ManufactureDate[STATISTICS_STRING_SIZE];
  wchar_t MechanicalRevision[STATISTICS_STRING_SIZE];
  wchar_t FirmwareRevision[STATISTICS_STRING_SIZE];
  wchar_t Interface[STATISTICS_STRING_SIZE];
  wchar_t InstallationDate[STATISTICS_STRING_SIZE];
} PosDeviceInformation;