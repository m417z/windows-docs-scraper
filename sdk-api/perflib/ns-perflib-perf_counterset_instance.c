typedef struct _PERF_COUNTERSET_INSTANCE {
  GUID  CounterSetGuid;
  ULONG dwSize;
  ULONG InstanceId;
  ULONG InstanceNameOffset;
  ULONG InstanceNameSize;
} PERF_COUNTERSET_INSTANCE, *PPERF_COUNTERSET_INSTANCE;