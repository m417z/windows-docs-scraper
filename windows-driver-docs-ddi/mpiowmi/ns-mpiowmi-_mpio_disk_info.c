typedef struct _MPIO_DISK_INFO {
  ULONG           NumberDrives;
  MPIO_DRIVE_INFO DriveInfo[1];
} MPIO_DISK_INFO, *PMPIO_DISK_INFO;