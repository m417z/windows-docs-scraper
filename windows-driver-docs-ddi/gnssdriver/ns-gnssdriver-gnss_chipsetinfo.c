typedef struct {
  ULONG Size;
  ULONG Version;
  WCHAR ManufacturerID[25];
  WCHAR HardwareID[25];
  WCHAR FirmwareVersion[20];
  BYTE  Unused[512];
} GNSS_CHIPSETINFO, *PGNSS_CHIPSETINFO;