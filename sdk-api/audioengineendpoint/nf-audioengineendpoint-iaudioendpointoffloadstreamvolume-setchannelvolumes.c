HRESULT SetChannelVolumes(
  [in] UINT32           u32ChannelCount,
  [in] FLOAT32          *pf32Volumes,
       AUDIO_CURVE_TYPE u32CurveType,
       HNSTIME          *pCurveDuration
);