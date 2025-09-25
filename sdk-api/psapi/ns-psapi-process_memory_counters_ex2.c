typedef struct _PROCESS_MEMORY_COUNTERS_EX2 {
  DWORD   cb;
  DWORD   PageFaultCount;
  SIZE_T  PeakWorkingSetSize;
  SIZE_T  WorkingSetSize;
  SIZE_T  QuotaPeakPagedPoolUsage;
  SIZE_T  QuotaPagedPoolUsage;
  SIZE_T  QuotaPeakNonPagedPoolUsage;
  SIZE_T  QuotaNonPagedPoolUsage;
  SIZE_T  PagefileUsage;
  SIZE_T  PeakPagefileUsage;
  SIZE_T  PrivateUsage;
  SIZE_T  PrivateWorkingSetSize;
  ULONG64 SharedCommitUsage;
} PROCESS_MEMORY_COUNTERS_EX2;