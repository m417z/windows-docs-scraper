typedef struct {
  KSP_NODE Property;
  ULONG    CurrentFrequency;
  ULONG    FrequencyRangeMin;
  ULONG    FrequencyRangeMax;
  ULONG    MilliSecondsLeft;
} KSPROPERTY_BDA_RF_TUNER_SCAN_STATUS_S, *PKSPROPERTY_BDA_RF_TUNER_SCAN_STATUS_S;