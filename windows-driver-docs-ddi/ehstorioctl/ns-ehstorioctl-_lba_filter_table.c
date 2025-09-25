typedef struct _LBA_FILTER_TABLE {
  ULONG   StructSize;
  BOOLEAN GlobalReadLock;
  LONG    Reserved1;
  BOOLEAN GlobalWriteLock;
  LONG    Reserved2;
  ULONG   LbaFilterCount;
  ULONG   LbaFilterSize;
  ULONG   LbaFiltersOffset;
} LBA_FILTER_TABLE, *PLBA_FILTER_TABLE;