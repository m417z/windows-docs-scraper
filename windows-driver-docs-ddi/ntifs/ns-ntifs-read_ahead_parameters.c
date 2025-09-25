typedef struct _READ_AHEAD_PARAMETERS {
  CSHORT NodeByteSize;
  ULONG  Granularity;
  ULONG  PipelinedRequestSize;
  ULONG  ReadAheadGrowthPercentage;
} READ_AHEAD_PARAMETERS, *PREAD_AHEAD_PARAMETERS;