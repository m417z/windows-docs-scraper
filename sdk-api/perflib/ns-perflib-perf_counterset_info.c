typedef struct _PERF_COUNTERSET_INFO {
  GUID  CounterSetGuid;
  GUID  ProviderGuid;
  ULONG NumCounters;
  ULONG InstanceType;
} PERF_COUNTERSET_INFO, *PPERF_COUNTERSET_INFO;