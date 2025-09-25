typedef struct _PEP_PPM_FEEDBACK_READ {
  ULONG CounterIndex;
  union {
    ULONG64 InstantaneousValue;
    struct {
      ULONG64 NominalCount;
      ULONG64 ActualCount;
    };
  };
} PEP_PPM_FEEDBACK_READ, *PPEP_PPM_FEEDBACK_READ;