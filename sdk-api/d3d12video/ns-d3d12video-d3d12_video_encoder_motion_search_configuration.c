typedef struct D3D12_VIDEO_ENCODER_MOTION_SEARCH_CONFIGURATION {
  BOOL                                         Enabled;
  D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE         MapSource;
  D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE MotionSearchMode;
  BOOL                                         BidirectionalRefFrameEnabled;
} D3D12_VIDEO_ENCODER_MOTION_SEARCH_CONFIGURATION;