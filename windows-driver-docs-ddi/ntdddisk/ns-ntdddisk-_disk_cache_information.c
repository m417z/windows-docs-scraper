typedef struct _DISK_CACHE_INFORMATION {
  BOOLEAN                       ParametersSavable;
  BOOLEAN                       ReadCacheEnabled;
  BOOLEAN                       WriteCacheEnabled;
  DISK_CACHE_RETENTION_PRIORITY ReadRetentionPriority;
  DISK_CACHE_RETENTION_PRIORITY WriteRetentionPriority;
  USHORT                        DisablePrefetchTransferLength;
  BOOLEAN                       PrefetchScalar;
  union {
    struct {
      USHORT Minimum;
      USHORT Maximum;
      USHORT MaximumBlocks;
    } ScalarPrefetch;
    struct {
      USHORT Minimum;
      USHORT Maximum;
    } BlockPrefetch;
  } DUMMYUNIONNAME;
} DISK_CACHE_INFORMATION, *PDISK_CACHE_INFORMATION;