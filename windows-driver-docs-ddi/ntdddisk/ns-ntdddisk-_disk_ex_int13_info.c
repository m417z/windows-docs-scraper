typedef struct _DISK_EX_INT13_INFO {
  USHORT  ExBufferSize;
  USHORT  ExFlags;
  ULONG   ExCylinders;
  ULONG   ExHeads;
  ULONG   ExSectorsPerTrack;
  ULONG64 ExSectorsPerDrive;
  USHORT  ExSectorSize;
  USHORT  ExReserved;
} DISK_EX_INT13_INFO, *PDISK_EX_INT13_INFO;