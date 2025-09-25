DWORD EnableThreadProfiling(
  [in]  HANDLE  ThreadHandle,
  [in]  DWORD   Flags,
  [in]  DWORD64 HardwareCounters,
  [out] HANDLE  *PerformanceDataHandle
);