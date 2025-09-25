typedef struct {
  LONGLONG         Current;
  LONGLONG         Stop;
  KS_SEEKING_FLAGS CurrentFlags;
  KS_SEEKING_FLAGS StopFlags;
} KSPROPERTY_POSITIONS, *PKSPROPERTY_POSITIONS;