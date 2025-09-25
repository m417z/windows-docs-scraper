typedef struct {
  ULONG Mode;
  ULONG StandardsSupported;
  ULONG MinFrequency;
  ULONG MaxFrequency;
  ULONG TuningGranularity;
  ULONG SettlingTime;
  ULONG ScanSensingRange;
  ULONG FineTuneSensingRange;
} TUNER_ANALOG_CAPS_S, *PTUNER_ANALOG_CAPS_S;