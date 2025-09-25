typedef struct _MS_SM_AdapterInformationQuery {
  ULONGLONG UniqueAdapterId;
  ULONG     HBAStatus;
  ULONG     NumberOfPorts;
  ULONG     VendorSpecificID;
  WCHAR     Manufacturer[64 + 1];
  WCHAR     SerialNumber[64 + 1];
  WCHAR     Model[256 + 1];
  WCHAR     ModelDescription[256 + 1];
  WCHAR     HardwareVersion[256 + 1];
  WCHAR     DriverVersion[256 + 1];
  WCHAR     OptionROMVersion[256 + 1];
  WCHAR     FirmwareVersion[256 + 1];
  WCHAR     DriverName[256 + 1];
  WCHAR     HBASymbolicName[256 + 1];
  WCHAR     RedundantOptionROMVersion[256 + 1];
  WCHAR     RedundantFirmwareVersion[256 + 1];
  WCHAR     MfgDomain[256 + 1];
} MS_SM_AdapterInformationQuery, *PMS_SM_AdapterInformationQuery;