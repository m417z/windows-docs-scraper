typedef struct _PO_FX_COMPONENT_PERF_SET {
  UNICODE_STRING        Name;
  ULONGLONG             Flags;
  PO_FX_PERF_STATE_UNIT Unit;
  PO_FX_PERF_STATE_TYPE Type;
  union {
    struct {
      ULONG             Count;
      PPO_FX_PERF_STATE States;
    } Discrete;
    struct {
      ULONGLONG Minimum;
      ULONGLONG Maximum;
    } Range;
  };
} PO_FX_COMPONENT_PERF_SET, *PPO_FX_COMPONENT_PERF_SET;