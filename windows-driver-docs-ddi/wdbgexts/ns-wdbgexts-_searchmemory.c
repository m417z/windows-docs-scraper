typedef struct _SEARCHMEMORY {
  ULONG64 SearchAddress;
  ULONG64 SearchLength;
  ULONG64 FoundAddress;
  ULONG   PatternLength;
  PVOID   Pattern;
} SEARCHMEMORY, *PSEARCHMEMORY;