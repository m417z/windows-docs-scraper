typedef struct _FILE_FS_SIZE_INFORMATION {
  LARGE_INTEGER TotalAllocationUnits;
  LARGE_INTEGER AvailableAllocationUnits;
  ULONG         SectorsPerAllocationUnit;
  ULONG         BytesPerSector;
} FILE_FS_SIZE_INFORMATION, *PFILE_FS_SIZE_INFORMATION;