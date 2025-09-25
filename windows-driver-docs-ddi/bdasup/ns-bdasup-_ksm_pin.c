typedef struct _KSM_PIN {
  KSMETHOD Method;
  union {
    ULONG PinId;
    ULONG PinType;
  };
  ULONG    Reserved;
} KSM_PIN, *PKSM_PIN;