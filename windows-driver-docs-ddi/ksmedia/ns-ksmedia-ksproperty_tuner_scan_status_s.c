typedef struct {
  KSPROPERTY    Property;
  TunerLockType LockStatus;
  ULONG         CurrentFrequency;
} KSPROPERTY_TUNER_SCAN_STATUS_S, *PKSPROPERTY_TUNER_SCAN_STATUS_S;