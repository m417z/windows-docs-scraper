typedef struct {
  KSPROPERTY Property;
  BOOL       fSupportsHardwareAssistedScanning;
  ULONG      SupportedBroadcastStandards;
  PVOID      GUIDBucket;
  ULONG      lengthofBucket;
} KSPROPERTY_TUNER_SCAN_CAPS_S, *PKSPROPERTY_TUNER_SCAN_CAPS_S;