typedef struct _RTL_SEGMENT_HEAP_MEMORY_SOURCE {
  ULONG  Flags;
  ULONG  MemoryTypeMask;
  ULONG  NumaNode;
  union {
    HANDLE                        PartitionHandle;
    RTL_SEGMENT_HEAP_VA_CALLBACKS *Callbacks;
  };
  SIZE_T Reserved[2];
} RTL_SEGMENT_HEAP_MEMORY_SOURCE, *PRTL_SEGMENT_HEAP_MEMORY_SOURCE;