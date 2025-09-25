typedef struct _PERF_COUNTER_IDENTIFIER {
  GUID  CounterSetGuid;
  ULONG Status;
  ULONG Size;
  ULONG CounterId;
  ULONG InstanceId;
  ULONG Index;
  ULONG Reserved;
} PERF_COUNTER_IDENTIFIER, *PPERF_COUNTER_IDENTIFIER;