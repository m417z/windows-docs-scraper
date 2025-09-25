typedef struct {
  KSPROPERTY Property;
  GUID       NetworkType;
  ULONG      BufferSize;
  PVOID      NetworkTunerCapabilities;
} KSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS_S, *PKSPROPERTY_TUNER_NETWORKTYPE_SCAN_CAPS_S;