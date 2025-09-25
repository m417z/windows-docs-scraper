typedef struct _MINIDUMP_MEMORY64_LIST {
  ULONG64                      NumberOfMemoryRanges;
  RVA64                        BaseRva;
  MINIDUMP_MEMORY_DESCRIPTOR64 MemoryRanges[0];
} MINIDUMP_MEMORY64_LIST, *PMINIDUMP_MEMORY64_LIST;