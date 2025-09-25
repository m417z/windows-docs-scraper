typedef struct _FSCTL_QUERY_STORAGE_CLASSES_OUTPUT {
  DWORD             Version;
  DWORD             Size;
  DWORD             Flags;
  DWORD             TotalNumberOfTiers;
  DWORD             NumberOfTiersReturned;
  FILE_STORAGE_TIER Tiers[ANYSIZE_ARRAY];
} FSCTL_QUERY_STORAGE_CLASSES_OUTPUT, *PFSCTL_QUERY_STORAGE_CLASSES_OUTPUT;