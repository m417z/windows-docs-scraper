typedef struct _KSM_BDA_PIN {
  KSMETHOD Method;
  union {
    ULONG PinId;
    ULONG PinType;
  };
  ULONG    Reserved;
} KSM_BDA_PIN, *PKSM_BDA_PIN;