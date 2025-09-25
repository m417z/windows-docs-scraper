typedef struct _CONFIGURATION_INFORMATION {
  ULONG   DiskCount;
  ULONG   FloppyCount;
  ULONG   CdRomCount;
  ULONG   TapeCount;
  ULONG   ScsiPortCount;
  ULONG   SerialCount;
  ULONG   ParallelCount;
  BOOLEAN AtDiskPrimaryAddressClaimed;
  BOOLEAN AtDiskSecondaryAddressClaimed;
  ULONG   Version;
  ULONG   MediumChangerCount;
} CONFIGURATION_INFORMATION, *PCONFIGURATION_INFORMATION;