typedef struct _DISK_PERFORMANCE {
  LARGE_INTEGER BytesRead;
  LARGE_INTEGER BytesWritten;
  LARGE_INTEGER ReadTime;
  LARGE_INTEGER WriteTime;
  LARGE_INTEGER IdleTime;
  ULONG         ReadCount;
  ULONG         WriteCount;
  ULONG         QueueDepth;
  ULONG         SplitCount;
  LARGE_INTEGER QueryTime;
  ULONG         StorageDeviceNumber;
  WCHAR         StorageManagerName[8];
} DISK_PERFORMANCE, *PDISK_PERFORMANCE;