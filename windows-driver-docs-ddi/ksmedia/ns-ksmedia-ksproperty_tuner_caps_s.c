typedef struct {
  KSPROPERTY   Property;
  ULONG        ModesSupported;
  KSPIN_MEDIUM VideoMedium;
  KSPIN_MEDIUM TVAudioMedium;
  KSPIN_MEDIUM RadioAudioMedium;
} KSPROPERTY_TUNER_CAPS_S, *PKSPROPERTY_TUNER_CAPS_S;