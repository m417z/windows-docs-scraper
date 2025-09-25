typedef struct _MSFC_FCAdapterHBAAttributes {
  ULONGLONG UniqueAdapterId;
  ULONG     HBAStatus;
  UCHAR     NodeWWN[8];
  ULONG     VendorSpecificID;
  ULONG     NumberOfPorts;
  WCHAR     Manufacturer[64 + 1];
  WCHAR     SerialNumber[64 + 1];
  WCHAR     Model[256 + 1];
  WCHAR     ModelDescription[256 + 1];
  WCHAR     NodeSymbolicName[256 + 1];
  WCHAR     HardwareVersion[256 + 1];
  WCHAR     DriverVersion[256 + 1];
  WCHAR     OptionROMVersion[256 + 1];
  WCHAR     FirmwareVersion[256 + 1];
  WCHAR     DriverName[256 + 1];
  WCHAR     MfgDomain[256 + 1];
} MSFC_FCAdapterHBAAttributes, *PMSFC_FCAdapterHBAAttributes;