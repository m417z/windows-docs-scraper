typedef struct _KSM_BDA_PIN_PAIR {
  KSMETHOD Method;
  union {
    ULONG InputPinId;
    ULONG InputPinType;
  };
  union {
    ULONG OutputPinId;
    ULONG OutputPinType;
  };
} KSM_BDA_PIN_PAIR, *PKSM_BDA_PIN_PAIR;