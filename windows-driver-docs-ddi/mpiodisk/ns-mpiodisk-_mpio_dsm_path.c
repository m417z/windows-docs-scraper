typedef struct _MPIO_DSM_Path {
  ULONGLONG DsmPathId;
  ULONGLONG Reserved;
  ULONG     PathWeight;
  ULONG     PrimaryPath;
} MPIO_DSM_Path, *PMPIO_DSM_Path;