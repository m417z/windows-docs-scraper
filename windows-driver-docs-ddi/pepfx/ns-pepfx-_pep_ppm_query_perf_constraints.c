typedef struct _PEP_PPM_QUERY_PERF_CONSTRAINTS {
  [out] ULONG GuaranteedPerformanceLimit;
  [out] ULONG LimitReasons;
} PEP_PPM_PERF_CONSTRAINTS, *PPEP_PPM_PERF_CONSTRAINTS;