typedef struct _DEVICE_DSM_TIERING_QUERY_OUTPUT {
  ULONG               Version;
  ULONG               Size;
  ULONG               Flags;
  ULONG               Reserved;
  ULONGLONG           Alignment;
  ULONG               TotalNumberOfRegions;
  ULONG               NumberOfRegionsReturned;
  STORAGE_TIER_REGION Regions[ANYSIZE_ARRAY];
} DEVICE_DSM_TIERING_QUERY_OUTPUT, *PDEVICE_DSM_TIERING_QUERY_OUTPUT;