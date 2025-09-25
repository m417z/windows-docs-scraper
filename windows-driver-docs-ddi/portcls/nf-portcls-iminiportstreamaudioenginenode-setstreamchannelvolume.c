NTSTATUS SetStreamChannelVolume(
  [in] UINT32           Channel,
  [in] LONG             TargetVolume,
  [in] AUDIO_CURVE_TYPE CurveType,
  [in] ULONGLONG        CurveDuration
);