typedef struct _RTL_HEAP_PARAMETERS {
  ULONG                    Length;
  SIZE_T                   SegmentReserve;
  SIZE_T                   SegmentCommit;
  SIZE_T                   DeCommitFreeBlockThreshold;
  SIZE_T                   DeCommitTotalFreeThreshold;
  SIZE_T                   MaximumAllocationSize;
  SIZE_T                   VirtualMemoryThreshold;
  SIZE_T                   InitialCommit;
  SIZE_T                   InitialReserve;
  PRTL_HEAP_COMMIT_ROUTINE CommitRoutine;
  SIZE_T                   Reserved[2];
} RTL_HEAP_PARAMETERS, *PRTL_HEAP_PARAMETERS;