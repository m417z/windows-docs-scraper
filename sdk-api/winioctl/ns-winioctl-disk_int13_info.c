typedef struct _DISK_INT13_INFO {
  WORD  DriveSelect;
  DWORD MaxCylinders;
  WORD  SectorsPerTrack;
  WORD  MaxHeads;
  WORD  NumberDrives;
} DISK_INT13_INFO, *PDISK_INT13_INFO;