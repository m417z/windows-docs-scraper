typedef struct _PERF_DATA_HEADER {
  ULONG      dwTotalSize;
  ULONG      dwNumCounters;
  LONGLONG   PerfTimeStamp;
  LONGLONG   PerfTime100NSec;
  LONGLONG   PerfFreq;
  SYSTEMTIME SystemTime;
} PERF_DATA_HEADER, *PPERF_DATA_HEADER;