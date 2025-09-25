typedef struct _PEP_QUERY_COMPONENT_PERF_SET {
  PEPHANDLE           DeviceHandle;
  ULONG               Component;
  ULONG               Set;
  ULONGLONG           Flags;
  PEP_PERF_STATE_UNIT Unit;
  PEP_PERF_STATE_TYPE Type;
  union {
    struct {
      ULONG Count;
    } Discrete;
    struct {
      ULONGLONG Minimum;
      ULONGLONG Maximum;
    } Range;
  };
} PEP_QUERY_COMPONENT_PERF_SET, *PPEP_QUERY_COMPONENT_PERF_SET;