typedef struct _DISK_CACHE_INFORMATION {
  BOOLEAN                       ParametersSavable;
  BOOLEAN                       ReadCacheEnabled;
  BOOLEAN                       WriteCacheEnabled;
  DISK_CACHE_RETENTION_PRIORITY ReadRetentionPriority;
  DISK_CACHE_RETENTION_PRIORITY WriteRetentionPriority;
  WORD                          DisablePrefetchTransferLength;
  BOOLEAN                       PrefetchScalar;
  union {
    struct {
      WORD Minimum;
      WORD Maximum;
      WORD MaximumBlocks;
    } ScalarPrefetch;
    struct {
      WORD Minimum;
      WORD Maximum;
    } BlockPrefetch;
  } DUMMYUNIONNAME;
} DISK_CACHE_INFORMATION, *PDISK_CACHE_INFORMATION;