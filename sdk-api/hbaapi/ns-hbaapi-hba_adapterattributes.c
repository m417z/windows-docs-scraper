typedef struct HBA_AdapterAttributes {
  char       Manufacturer[64];
  char       SerialNumber[64];
  char       Model[256];
  char       ModelDescription[256];
  HBA_WWN    NodeWWN;
  char       NodeSymbolicName[256];
  char       HardwareVersion[256];
  char       DriverVersion[256];
  char       OptionROMVersion[256];
  char       FirmwareVersion[256];
  HBA_UINT32 VendorSpecificID;
  HBA_UINT32 NumberOfPorts;
  char       DriverName[256];
} HBA_ADAPTERATTRIBUTES, *PHBA_ADAPTERATTRIBUTES;