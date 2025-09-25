typedef struct DISK_SPACE_INFORMATION {
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
  DWORD     SectorsPerAllocationUnit;
  DWORD     BytesPerSector;
} DISK_SPACE_INFORMATION;