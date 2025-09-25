typedef struct {
  KSPROPERTY Property;
  ULONG      CurrentFrequency;
  ULONG      PLLOffset;
  ULONG      SignalStrength;
  ULONG      Busy;
} KSPROPERTY_TUNER_STATUS_S, *PKSPROPERTY_TUNER_STATUS_S;