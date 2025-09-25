typedef struct {
  KSPROPERTY Property;
  ULONG      Frequency;
  ULONG      LastFrequency;
  ULONG      TuningFlags;
  ULONG      VideoSubChannel;
  ULONG      AudioSubChannel;
  ULONG      Channel;
  ULONG      Country;
} KSPROPERTY_TUNER_FREQUENCY_S, *PKSPROPERTY_TUNER_FREQUENCY_S;