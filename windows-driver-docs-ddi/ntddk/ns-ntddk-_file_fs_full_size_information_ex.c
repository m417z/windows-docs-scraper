typedef struct _FILE_FS_FULL_SIZE_INFORMATION_EX {
  ULONGLONG ActualTotalAllocationUnits;
  ULONGLONG ActualAvailableAllocationUnits;
  ULONGLONG ActualPoolUnavailableAllocationUnits;
  ULONGLONG CallerTotalAllocationUnits;
  ULONGLONG CallerAvailableAllocationUnits;
  ULONGLONG CallerPoolUnavailableAllocationUnits;
  ULONGLONG UsedAllocationUnits;
  ULONGLONG TotalReservedAllocationUnits;
  ULONGLONG VolumeStorageReserveAllocationUnits;
  ULONGLONG AvailableCommittedAllocationUnits;
  ULONGLONG PoolAvailableAllocationUnits;
  ULONG     SectorsPerAllocationUnit;
  ULONG     BytesPerSector;
} FILE_FS_FULL_SIZE_INFORMATION_EX, *PFILE_FS_FULL_SIZE_INFORMATION_EX;