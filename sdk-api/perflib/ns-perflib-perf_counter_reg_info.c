typedef struct _PERF_COUNTER_REG_INFO {
  ULONG     CounterId;
  ULONG     Type;
  ULONGLONG Attrib;
  ULONG     DetailLevel;
  LONG      DefaultScale;
  ULONG     BaseCounterId;
  ULONG     PerfTimeId;
  ULONG     PerfFreqId;
  ULONG     MultiId;
  ULONG     AggregateFunc;
  ULONG     Reserved;
} PERF_COUNTER_REG_INFO, *PPERF_COUNTER_REG_INFO;