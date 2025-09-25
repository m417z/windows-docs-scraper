typedef struct _PERFORMANCE_INFORMATION {
  DWORD  cb;
  SIZE_T CommitTotal;
  SIZE_T CommitLimit;
  SIZE_T CommitPeak;
  SIZE_T PhysicalTotal;
  SIZE_T PhysicalAvailable;
  SIZE_T SystemCache;
  SIZE_T KernelTotal;
  SIZE_T KernelPaged;
  SIZE_T KernelNonpaged;
  SIZE_T PageSize;
  DWORD  HandleCount;
  DWORD  ProcessCount;
  DWORD  ThreadCount;
} PERFORMANCE_INFORMATION, *PPERFORMANCE_INFORMATION, PERFORMACE_INFORMATION, *PPERFORMACE_INFORMATION;