typedef struct _AVRF_HEAP_ALLOCATION {
  ULONG64                     HeapHandle;
  ULONG64                     UserAllocation;
  ULONG64                     UserAllocationSize;
  ULONG64                     Allocation;
  ULONG64                     AllocationSize;
  ULONG                       UserAllocationState;
  ULONG                       HeapState;
  ULONG64                     HeapContext;
  PAVRF_BACKTRACE_INFORMATION BackTraceInformation;
} AVRF_HEAP_ALLOCATION, *PAVRF_HEAP_ALLOCATION;