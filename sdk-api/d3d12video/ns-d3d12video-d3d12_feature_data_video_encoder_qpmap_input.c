typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_QPMAP_INPUT {
  UINT                                       NodeIndex;
  D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO SessionInfo;
  D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE       MapSource;
  BOOL                                       IsSupported;
  UINT                                       MapSourcePreferenceRanking;
  UINT                                       BlockSize;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_QPMAP_INPUT;