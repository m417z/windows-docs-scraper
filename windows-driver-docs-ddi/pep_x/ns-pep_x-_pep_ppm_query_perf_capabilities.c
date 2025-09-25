typedef struct _PEP_PPM_QUERY_PERF_CAPABILITIES {
  [out] ULONG HighestPerformance;
  [out] ULONG NominalPerformance;
  [out] ULONG LowestNonlinearPerformance;
  [out] ULONG LowestPerformance;
  [out] ULONG DomainId;
  [out] ULONG DomainMembers;
} PEP_PPM_QUERY_PERF_CAPABILITIES, *PPEP_PPM_QUERY_PERF_CAPABILITIES;