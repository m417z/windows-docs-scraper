typedef struct _PERF_COUNTER_DEFINITION {
  DWORD  ByteLength;
  DWORD  CounterNameTitleIndex;
#if ...
  DWORD  CounterNameTitle;
#else
  LPWSTR CounterNameTitle;
#endif
  DWORD  CounterHelpTitleIndex;
#if ...
  DWORD  CounterHelpTitle;
#else
  LPWSTR CounterHelpTitle;
#endif
  LONG   DefaultScale;
  DWORD  DetailLevel;
  DWORD  CounterType;
  DWORD  CounterSize;
  DWORD  CounterOffset;
} PERF_COUNTER_DEFINITION, *PPERF_COUNTER_DEFINITION;