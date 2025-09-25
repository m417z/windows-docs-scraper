typedef enum _MEMORY_CACHING_TYPE {
  MmNonCached,
  MmCached,
  MmWriteCombined,
  MmHardwareCoherentCached,
  MmNonCachedUnordered,
  MmUSWCCached,
  MmMaximumCacheType,
  MmNotMapped
} MEMORY_CACHING_TYPE;