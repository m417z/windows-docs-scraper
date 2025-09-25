EVT_ACX_RAMPED_VOLUME_ASSIGN_LEVEL EvtAcxRampedVolumeAssignLevel;

NTSTATUS EvtAcxRampedVolumeAssignLevel(
  ACXVOLUME Volume,
  ULONG Channel,
  LONG VolumeLevel,
  ACX_VOLUME_CURVE_TYPE CurveType,
  ULONGLONG CurveDuration
)
{...}