typedef struct _STORAGE_WRITE_CACHE_PROPERTY {
  ULONG              Version;
  ULONG              Size;
  WRITE_CACHE_TYPE   WriteCacheType;
  WRITE_CACHE_ENABLE WriteCacheEnabled;
  WRITE_CACHE_CHANGE WriteCacheChangeable;
  WRITE_THROUGH      WriteThroughSupported;
  BOOLEAN            FlushCacheSupported;
  BOOLEAN            UserDefinedPowerProtection;
  BOOLEAN            NVCacheEnabled;
} STORAGE_WRITE_CACHE_PROPERTY, *PSTORAGE_WRITE_CACHE_PROPERTY;