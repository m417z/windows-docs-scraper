typedef struct _PEP_PPM_PERF_SET {
  [in] ULONG MinimumPerformance;
  [in] ULONG MaximumPerformance;
  [in] ULONG DesiredPerformance;
  [in] ULONG TimeWindow;
  [in] ULONG PerformanceTolerance;
} PEP_PPM_PERF_SET, *PPEP_PPM_PERF_SET;