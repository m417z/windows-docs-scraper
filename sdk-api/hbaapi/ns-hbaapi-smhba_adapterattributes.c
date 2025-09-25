typedef struct SMHBA_AdapterAttributes {
  char       Manufacturer[64];
  char       SerialNumber[64];
  char       Model[256];
  char       ModelDescription[256];
  char       HardwareVersion[256];
  char       DriverVersion[256];
  char       OptionROMVersion[256];
  char       FirmwareVersion[256];
  HBA_UINT32 VendorSpecificID;
  char       DriverName[256];
  char       HBASymbolicName[256];
  char       RedundantOptionROMVersion[256];
  char       RedundantFirmwareVersion[256];
} SMHBA_ADAPTERATTRIBUTES, *PSMHBA_ADAPTERATTRIBUTES;