typedef struct _PERF_COUNTER_HEADER {
  ULONG               dwStatus;
  PerfCounterDataType dwType;
  ULONG               dwSize;
  ULONG               Reserved;
} PERF_COUNTER_HEADER, *PPERF_COUNTER_HEADER;