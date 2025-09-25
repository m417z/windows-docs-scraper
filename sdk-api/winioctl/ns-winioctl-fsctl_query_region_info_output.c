typedef struct _FSCTL_QUERY_REGION_INFO_OUTPUT {
  DWORD                    Version;
  DWORD                    Size;
  DWORD                    Flags;
  DWORD                    Reserved;
  DWORDLONG                Alignment;
  DWORD                    TotalNumberOfRegions;
  DWORD                    NumberOfRegionsReturned;
  FILE_STORAGE_TIER_REGION Regions[ANYSIZE_ARRAY];
} FSCTL_QUERY_REGION_INFO_OUTPUT, *PFSCTL_QUERY_REGION_INFO_OUTPUT;