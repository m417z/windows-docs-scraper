typedef struct {
  KSPROPERTY   Property;
  ULONG        Capabilities;
  KSPIN_MEDIUM InputMedium;
  KSPIN_MEDIUM OutputMedium;
} KSPROPERTY_TVAUDIO_CAPS_S, *PKSPROPERTY_TVAUDIO_CAPS_S;