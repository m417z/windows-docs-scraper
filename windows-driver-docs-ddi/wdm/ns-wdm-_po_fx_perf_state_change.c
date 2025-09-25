typedef struct _PO_FX_PERF_STATE_CHANGE {
  ULONG Set;
  union {
    ULONG     StateIndex;
    ULONGLONG StateValue;
  };
} PO_FX_PERF_STATE_CHANGE, *PPO_FX_PERF_STATE_CHANGE;