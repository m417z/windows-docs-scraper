typedef struct _DISK_INT13_INFO {
  USHORT DriveSelect;
  ULONG  MaxCylinders;
  USHORT SectorsPerTrack;
  USHORT MaxHeads;
  USHORT NumberDrives;
} DISK_INT13_INFO, *PDISK_INT13_INFO;