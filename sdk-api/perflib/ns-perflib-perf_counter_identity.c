typedef struct _PERF_COUNTER_IDENTITY {
  GUID  CounterSetGuid;
  ULONG BufferSize;
  ULONG CounterId;
  ULONG InstanceId;
  ULONG MachineOffset;
  ULONG NameOffset;
  ULONG Reserved;
} PERF_COUNTER_IDENTITY, *PPERF_COUNTER_IDENTITY;