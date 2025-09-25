typedef struct _FILE_FS_CONTROL_INFORMATION {
  LARGE_INTEGER FreeSpaceStartFiltering;
  LARGE_INTEGER FreeSpaceThreshold;
  LARGE_INTEGER FreeSpaceStopFiltering;
  LARGE_INTEGER DefaultQuotaThreshold;
  LARGE_INTEGER DefaultQuotaLimit;
  ULONG         FileSystemControlFlags;
} FILE_FS_CONTROL_INFORMATION, *PFILE_FS_CONTROL_INFORMATION;