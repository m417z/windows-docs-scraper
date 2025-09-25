typedef struct _ScsiReadCapacity_IN {
  ULONGLONG UniqueSessionId;
  ULONGLONG Lun;
} ScsiReadCapacity_IN, *PScsiReadCapacity_IN;