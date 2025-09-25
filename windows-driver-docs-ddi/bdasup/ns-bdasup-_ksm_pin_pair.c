typedef struct _KSM_PIN_PAIR {
  KSMETHOD Method;
  ULONG    InputPinId;
  ULONG    OutputPinId;
  ULONG    Reserved;
} KSM_PIN_PAIR, *PKSM_PIN_PAIR;