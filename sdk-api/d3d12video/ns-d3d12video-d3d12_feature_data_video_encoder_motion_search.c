typedef struct D3D12_FEATURE_DATA_VIDEO_ENCODER_MOTION_SEARCH {
  UINT                                                                NodeIndex;
  D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO                          SessionInfo;
  D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE                        MotionSearchMode;
  D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE                                MapSource;
  BOOL                                                                BidirectionalRefFrameEnabled;
  D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAGS                     SupportFlags;
  UINT                                                                MaxMotionHints;
  UINT                                                                MinDeviation;
  UINT                                                                MaxDeviation;
  UINT                                                                MapSourcePreferenceRanking;
  D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION_SUPPORT_FLAGS MotionUnitPrecisionSupport;
} D3D12_FEATURE_DATA_VIDEO_ENCODER_MOTION_SEARCH;