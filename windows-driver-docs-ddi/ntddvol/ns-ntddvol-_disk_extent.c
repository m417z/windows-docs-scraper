typedef struct _DISK_EXTENT {
  ULONG         DiskNumber;
  LARGE_INTEGER StartingOffset;
  LARGE_INTEGER ExtentLength;
} DISK_EXTENT, *PDISK_EXTENT;