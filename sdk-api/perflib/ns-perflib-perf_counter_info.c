typedef struct _PERF_COUNTER_INFO {
  ULONG     CounterId;
  ULONG     Type;
  ULONGLONG Attrib;
  ULONG     Size;
  ULONG     DetailLevel;
  LONG      Scale;
  ULONG     Offset;
} PERF_COUNTER_INFO, *PPERF_COUNTER_INFO;