typedef struct _CSV_NAMESPACE_INFO {
  DWORD         Version;
  DWORD         DeviceNumber;
  LARGE_INTEGER StartingOffset;
  DWORD         SectorSize;
} CSV_NAMESPACE_INFO, *PCSV_NAMESPACE_INFO;