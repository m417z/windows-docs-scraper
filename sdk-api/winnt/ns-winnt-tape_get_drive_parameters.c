typedef struct _TAPE_GET_DRIVE_PARAMETERS {
  BOOLEAN ECC;
  BOOLEAN Compression;
  BOOLEAN DataPadding;
  BOOLEAN ReportSetmarks;
  DWORD   DefaultBlockSize;
  DWORD   MaximumBlockSize;
  DWORD   MinimumBlockSize;
  DWORD   MaximumPartitionCount;
  DWORD   FeaturesLow;
  DWORD   FeaturesHigh;
  DWORD   EOTWarningZoneSize;
} TAPE_GET_DRIVE_PARAMETERS, *PTAPE_GET_DRIVE_PARAMETERS;