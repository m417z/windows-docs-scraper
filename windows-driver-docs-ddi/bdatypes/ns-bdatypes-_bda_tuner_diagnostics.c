typedef struct _BDA_TUNER_DIAGNOSTICS {
  PBDARESULT lResult;
  ULONG      ulSignalLevel;
  ULONG      ulSignalLevelQuality;
  ULONG      ulSignalNoiseRatio;
} BDA_TUNER_DIAGNOSTICS, *PBDA_TUNER_DIAGNOSTICS;