typedef struct _FILE_REGION_OUTPUT {
  ULONG            Flags;
  ULONG            TotalRegionEntryCount;
  ULONG            RegionEntryCount;
  ULONG            Reserved;
  FILE_REGION_INFO Region[1];
} FILE_REGION_OUTPUT, *PFILE_REGION_OUTPUT;