typedef struct _HYBRID_INFORMATION {
  ULONG          Version;
  ULONG          Size;
  BOOLEAN        HybridSupported;
  NVCACHE_STATUS Status;
  NVCACHE_TYPE   CacheTypeEffective;
  NVCACHE_TYPE   CacheTypeDefault;
  ULONG          FractionBase;
  ULONGLONG      CacheSize;
  struct {
    ULONG WriteCacheChangeable : 1;
    ULONG WriteThroughIoSupported : 1;
    ULONG FlushCacheSupported : 1;
    ULONG Removable : 1;
    ULONG ReservedBits : 28;
  } Attributes;
  struct {
    UCHAR                             PriorityLevelCount;
    BOOLEAN                           MaxPriorityBehavior;
    UCHAR                             OptimalWriteGranularity;
    UCHAR                             Reserved;
    ULONG                             DirtyThresholdLow;
    ULONG                             DirtyThresholdHigh;
    struct {
      ULONG CacheDisable : 1;
      ULONG SetDirtyThreshold : 1;
      ULONG PriorityDemoteBySize : 1;
      ULONG PriorityChangeByLbaRange : 1;
      ULONG Evict : 1;
      ULONG ReservedBits : 27;
      ULONG MaxEvictCommands;
      ULONG MaxLbaRangeCountForEvict;
      ULONG MaxLbaRangeCountForChangeLba;
    } SupportedCommands;
    NVCACHE_PRIORITY_LEVEL_DESCRIPTOR Priority[0];
  } Priorities;
} HYBRID_INFORMATION, *PHYBRID_INFORMATION;