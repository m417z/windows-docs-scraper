typedef struct _RTL_SEGMENT_HEAP_PARAMETERS {
  USHORT                         Version;
  USHORT                         Size;
  ULONG                          Flags;
  RTL_SEGMENT_HEAP_MEMORY_SOURCE MemorySource;
  SIZE_T                         Reserved[4];
} RTL_SEGMENT_HEAP_PARAMETERS, *PRTL_SEGMENT_HEAP_PARAMETERS;