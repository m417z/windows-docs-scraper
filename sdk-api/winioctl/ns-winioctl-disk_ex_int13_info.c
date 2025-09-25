typedef struct _DISK_EX_INT13_INFO {
  WORD    ExBufferSize;
  WORD    ExFlags;
  DWORD   ExCylinders;
  DWORD   ExHeads;
  DWORD   ExSectorsPerTrack;
  DWORD64 ExSectorsPerDrive;
  WORD    ExSectorSize;
  WORD    ExReserved;
} DISK_EX_INT13_INFO, *PDISK_EX_INT13_INFO;