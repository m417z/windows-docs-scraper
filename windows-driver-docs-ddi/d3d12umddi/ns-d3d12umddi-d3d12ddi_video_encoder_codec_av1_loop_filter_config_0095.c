typedef struct D3D12DDI_VIDEO_ENCODER_CODEC_AV1_LOOP_FILTER_CONFIG_0095 {
  UINT64 LoopFilterLevel[2];
  UINT64 LoopFilterLevelU;
  UINT64 LoopFilterLevelV;
  UINT64 LoopFilterSharpnessLevel;
  UINT64 LoopFilterDeltaEnabled;
  UINT64 UpdateRefDelta;
  INT64  RefDeltas[8];
  UINT64 UpdateModeDelta;
  INT64  ModeDeltas[2];
} D3D12DDI_VIDEO_ENCODER_CODEC_AV1_LOOP_FILTER_CONFIG_0095;