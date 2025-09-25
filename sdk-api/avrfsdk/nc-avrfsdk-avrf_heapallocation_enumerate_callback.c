AVRF_HEAPALLOCATION_ENUMERATE_CALLBACK AvrfHeapallocationEnumerateCallback;

ULONG AvrfHeapallocationEnumerateCallback(
  PAVRF_HEAP_ALLOCATION HeapAllocation,
  PVOID EnumerationContext,
  PULONG EnumerationLevel
)
{...}