typedef struct _STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR {
  ULONG Version;
  ULONG Size;
  ULONG BytesPerCacheLine;
  ULONG BytesOffsetForCacheAlignment;
  ULONG BytesPerLogicalSector;
  ULONG BytesPerPhysicalSector;
  ULONG BytesOffsetForSectorAlignment;
} STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR, *PSTORAGE_ACCESS_ALIGNMENT_DESCRIPTOR;