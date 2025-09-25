typedef struct {
  KSP_NODE Property;
  ULONG    Mode;
  ULONG    AnalogStandardsSupported;
  ULONG    DigitalStandardsSupported;
  ULONG    MinFrequency;
  ULONG    MaxFrequency;
  ULONG    SettlingTime;
  ULONG    AnalogSensingRange;
  ULONG    DigitalSensingRange;
  ULONG    MilliSecondsPerMHz;
} KSPROPERTY_BDA_RF_TUNER_CAPS_S, *PKSPROPERTY_BDA_RF_TUNER_CAPS_S;