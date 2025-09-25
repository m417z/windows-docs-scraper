typedef struct _TAPE_GET_DRIVE_PARAMETERS {
  BOOLEAN ECC;
  BOOLEAN Compression;
  BOOLEAN DataPadding;
  BOOLEAN ReportSetmarks;
  ULONG   DefaultBlockSize;
  ULONG   MaximumBlockSize;
  ULONG   MinimumBlockSize;
  ULONG   MaximumPartitionCount;
  ULONG   FeaturesLow;
  ULONG   FeaturesHigh;
  ULONG   EOTWarningZoneSize;
} TAPE_GET_DRIVE_PARAMETERS, *PTAPE_GET_DRIVE_PARAMETERS;