typedef struct D3D12_VIDEO_ENCODER_MOVEREGION_INFO {
  UINT                                                  NumMoveRegions;
  D3D12_VIDEO_ENCODER_MOVE_RECT                         *pMoveRegions;
  D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_CONFIG   MotionSearchModeConfiguration;
  UINT                                                  SourceDPBFrameReference;
  D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION MotionUnitPrecision;
  D3D12_VIDEO_ENCODER_MOVEREGION_INFO_FLAGS             Flags;
} D3D12_VIDEO_ENCODER_MOVEREGION_INFO;