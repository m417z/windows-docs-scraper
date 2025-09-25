typedef struct {
  KSPROPERTY Property;
  ULONG      PinId;
  union {
    ULONG Reserved;
    ULONG Flags;
  };
} KSP_PIN, *PKSP_PIN;