typedef struct _ScsiReadCapacity_IN {
  UCHAR     Cdb[10];
  UCHAR     HbaPortWWN[8];
  UCHAR     DiscoveredPortWWN[8];
  ULONGLONG FcLun;
} ScsiReadCapacity_IN, *PScsiReadCapacity_IN;