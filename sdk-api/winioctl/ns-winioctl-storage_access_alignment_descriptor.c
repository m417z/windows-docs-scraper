typedef struct _STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR {
  DWORD Version;
  DWORD Size;
  DWORD BytesPerCacheLine;
  DWORD BytesOffsetForCacheAlignment;
  DWORD BytesPerLogicalSector;
  DWORD BytesPerPhysicalSector;
  DWORD BytesOffsetForSectorAlignment;
} STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR, *PSTORAGE_ACCESS_ALIGNMENT_DESCRIPTOR;