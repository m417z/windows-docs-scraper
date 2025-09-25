typedef struct _PERF_COUNTERSET_REG_INFO {
  GUID  CounterSetGuid;
  ULONG CounterSetType;
  ULONG DetailLevel;
  ULONG NumCounters;
  ULONG InstanceType;
} PERF_COUNTERSET_REG_INFO, *PPERF_COUNTERSET_REG_INFO;