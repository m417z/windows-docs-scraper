typedef struct _REFS_DEALLOCATE_RANGES_INPUT_BUFFER_EX {
  ULONG                            RangeCount;
  REFS_DEALLOCATE_RANGES_ALLOCATOR Allocator;
  LONGLONG                         StreamReserveUpdateCount;
  ULONG                            OffsetToRanges;
  ULONG                            OffsetToLeakCounts;
  ULONGLONG                        Reserved[2];
} REFS_DEALLOCATE_RANGES_INPUT_BUFFER_EX, *PREFS_DEALLOCATE_RANGES_INPUT_BUFFER_EX;