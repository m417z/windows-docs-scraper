BOOL GetProcessMemoryInfo(
  [in]  HANDLE                   Process,
  [out] PPROCESS_MEMORY_COUNTERS ppsmemCounters,
  [in]  DWORD                    cb
);