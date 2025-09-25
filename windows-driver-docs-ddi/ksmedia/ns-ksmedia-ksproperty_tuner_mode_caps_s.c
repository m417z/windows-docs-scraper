typedef struct {
  KSPROPERTY Property;
  ULONG      Mode;
  ULONG      StandardsSupported;
  ULONG      MinFrequency;
  ULONG      MaxFrequency;
  ULONG      TuningGranularity;
  ULONG      NumberOfInputs;
  ULONG      SettlingTime;
  ULONG      Strategy;
} KSPROPERTY_TUNER_MODE_CAPS_S, *PKSPROPERTY_TUNER_MODE_CAPS_S;